#include "bits/stdc++.h"
using namespace std;

int arr[1003],brr[53];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int N;cin>>N;
    for(int i=1;i<=N;++i){
        cin>>brr[i];
        arr[brr[i]]++;
    }

    set<int>S(brr+1,brr+1+N);
    int pre=-1557;
    while(!S.empty()){
        const int n=(int)S.size();
        if(n==1){
            int x=*S.begin();
            while(arr[x]--)cout<<x<<" ";
            S.erase(x);
        }else if(n==2){
            auto it=S.begin();
            int x=*it; ++it;
            int y=*it;
            
            if(x+1==y){
                while(arr[y]--)cout<<y<<" ";
                while(arr[x]--)cout<<x<<" ";
            }else{
                if(pre+1==x){
                    cout<<y<<" ";
                    --arr[y];
                }
                while(arr[x]--)cout<<x<<" ";
                while(arr[y]--)cout<<y<<" ";
            }
            S.erase(x);
            S.erase(y);
        }else{
            auto it=S.begin();
            int x=*it; ++it;
            int y=*it; ++it;
            int z=*it;
            
            if(pre+1==x){
                cout<<y<<" "; --arr[y];
                pre=y;
            }else{
                while(arr[x]--)cout<<x<<" ";
                pre=x;
            }
            
            if(arr[x]<=0)S.erase(x);
            if(arr[y]<=0)S.erase(y);
            if(arr[z]<=0)S.erase(z);
        }
    }
    cout<<"\n";
    
    return 0;
}
