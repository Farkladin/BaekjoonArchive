#include "bits/stdc++.h"
using namespace std;
int dist(int x,int y,int X,int Y){
    return (x-X)*(x-X)+(y-Y)*(y-Y);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        int n;cin>>n;
        int ans=0;
        while(n--){
            int x,y,r;cin>>x>>y>>r;
            assert(dist(x1,y1,x,y)!=r*r&&dist(x2,y2,x,y)!=r*r);
            ans+=(dist(x1,y1,x,y)<r*r&&dist(x2,y2,x,y)>r*r)||(dist(x1,y1,x,y)>r*r&&dist(x2,y2,x,y)<r*r);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
