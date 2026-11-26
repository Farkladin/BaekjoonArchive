#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    int cur=1;
    bool flag=false;
    for(int i=1;i<N;i++){
        vector<pair<int,int> >vp;
        int x;cin>>x;
        int tmp=2e9;
        if(x==1){
            char d;int c;
            cin>>c>>d;
            if(d=='L'){
                if(c==M)flag=true;
                tmp=min(tmp,max(c+1,cur));
            }else{
                if(cur>c-1)flag=true;
            }
        }else if(x==2){
            char d1,d2;int c1,c2;
            cin>>c1>>d1>>c2>>d2;
            if(c1>c2){
                swap(c1,c2);
                swap(d1,d2);
            }
            if(d1=='L'&&d2=='L'){
                if(c2==M)flag=true;
                tmp=min(tmp,max(c2+1,cur));
            }else if(d1=='R'&&d2=='R'){
                if(cur>c1-1)flag=true;
            }else if(d1=='R'){
                vp={{1,c1-1},{c2+1,M}};
                if(cur>c1-1&&c2==M)flag=true;
                else if(cur>c1-1)tmp=min(tmp,max(c2+1,cur));
            }else{
                if(cur>c2-1||c1+1>c2-1)flag=true;
                else tmp=min(tmp,max(c1+1,cur));
            }
        }
        if(tmp!=2e9)cur=tmp;
    }
    cout<<(flag?"NO\n":"YES\n");
    return 0;
}
