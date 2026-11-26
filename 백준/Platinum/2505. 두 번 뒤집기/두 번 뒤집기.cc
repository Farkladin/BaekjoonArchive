#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N;cin>>N;
    vector<int>arr(N+3),brr(N+3),sorted(N+3);
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
        brr[arr[i]]=i;
        sorted[i]=i;
    }
    
    for(int i=1; i<=N; ++i){
        vector<int>v(arr);
        int s=i,e=brr[i];
        if(s>e)swap(s,e);
        reverse(v.begin()+s,v.begin()+e+1);
        
        int st=0, cnt=1;
        for(int i=1;i<=N;i++){
            if(v[i]==v[i+1]+1){
                if(st==0){
                    cnt=2;
                    st=i;
                }else{
                    cnt++;
                }
            }else if(st){
                break;
            }
        }
        reverse(v.begin()+st,v.begin()+st+cnt);
        
        if(sorted == v){
            cout<<s<<" "<<e<<"\n";
            if(st)cout<<st<<" "<<st+cnt-1<<"\n";
            else cout<<"1 1\n";
            return 0;
        }
    }
    
    return 1;
}
