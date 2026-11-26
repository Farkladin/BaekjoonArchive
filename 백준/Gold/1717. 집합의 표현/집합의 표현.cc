#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
int pos[1000003];
void sfind(int &x){
    int z=x;
    while(z!=pos[z])z=pos[z];
    while(x!=pos[x]){
        int tmp=x;
        x=pos[x];
        pos[tmp]=z;
    }
}
void uni(int x,int y){
    sfind(x);
    sfind(y);
    pos[y]=x;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)pos[i]=i;
    while(m--){
        int q,a,b;cin>>q>>a>>b;
        if(q==0){
            uni(a,b);
        }else{
            sfind(a);
            sfind(b);
            cout<<(a==b?"YES\n":"NO\n");
        }
    }
    return 0;
}
