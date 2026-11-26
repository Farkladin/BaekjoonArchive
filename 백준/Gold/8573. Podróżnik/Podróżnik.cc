#include "bits/stdc++.h"
using namespace std;
using ll=long long;
const ll dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int mp[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    mp['N']=0;
    mp['S']=1;
    mp['W']=2;
    mp['E']=3;
    ll xm=0,ym=0,xM=0,yM=0,x=0,y=0;
    int n;cin>>n;
    while(n--){
        ll k;string s;cin>>k>>s;
        ll Dx=0,Dy=0;
        for(char c:s){
            Dx+=dx[mp[c]];
            Dy+=dy[mp[c]];
            x+=dx[mp[c]];
            y+=dy[mp[c]];
            xm=min(xm,x);
            xM=max(xM,x);
            ym=min(ym,y);
            yM=max(yM,y);
        }
        x+=(k-2)*Dx;
        y+=(k-2)*Dy;
        xm=min(xm,x);
        xM=max(xM,x);
        ym=min(ym,y);
        yM=max(yM,y);
        for(char c:s){
            x+=dx[mp[c]];
            y+=dy[mp[c]];
            xm=min(xm,x);
            xM=max(xM,x);
            ym=min(ym,y);
            yM=max(yM,y);
        }
    }
    cout<<xM-xm<<" "<<yM-ym<<"\n";
    return 0;
}
