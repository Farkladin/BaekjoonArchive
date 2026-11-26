#include "bits/stdc++.h"
using namespace std;

int anc[20003],dist[20003];

int find(int x){
    if(anc[x]==x)return x;
    int root=find(anc[x]);
    dist[x]+=dist[anc[x]];
    anc[x]=root;
    return root;
}
void solve(){
    int N;cin>>N;
    for(int i=1;i<=N;++i){
        anc[i]=i;
        dist[i]=0;
    }
    
    int cnt=0;
    Loop:{
        char c;cin>>c;
        switch(c){
            case 'I':{
                ++cnt;
                int I,J; cin>>I>>J;
                anc[I]=J;
                dist[I]=abs(I-J)%1000;
                break;
            }
            case 'E':{
                int I;cin>>I;
                find(I);
                cout<<dist[I]<<"\n";
                break;
            }
            default:
                goto breakLoop;
                break;
        }
    }goto Loop;
    
    breakLoop:
    return;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int T;cin>>T;
    while(T--) solve();
    
    return 0;
}
