#include "bits/stdc++.h"
using namespace std;
using ll=long long;
bool xis[1000003],yis[1000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,q;cin>>n>>q;
    ll x=0,y=0,xnt=0,ynt=0;
    while(q--){
        char c;ll a;cin>>c>>a;
        if(c=='R'){
            if(xis[a])cout<<"0\n";
            else{
                cout<<(n*(n+1)>>1)+a*(n-ynt)-x<<"\n";
                xis[a]=true;
                xnt++;
                y+=a;
            }
        }else{
            if(yis[a])cout<<"0\n";
            else{
                cout<<(n*(n+1)>>1)+a*(n-xnt)-y<<"\n";
                yis[a]=true;
                ynt++;
                x+=a;
            }
        }
    }
    return 0;
}
