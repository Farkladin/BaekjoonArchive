#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int c;cin>>c;
    while(c--){
        int n;cin>>n;
        using tri=array<ll,3>;
        vector<tri >vp(n);
        for(int i=0;i<n;i++){
            cin>>vp[i][0]>>vp[i][1];
            vp[i][2]=i;
        }
        
        sort(vp.begin(),vp.end(),[](const tri &a,const tri &b)->bool{
            return a[1]<b[1]||(a[1]==b[1]&&a[0]<b[0]);
        });
        
        auto ccw=[&vp](const tri &a,const tri &b,const tri &c)->int{
            ll cp=(b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
            if(cp>0)return 1;
            if(cp<0)return -1;
            return 0;
        };
        
        auto dist=[](const tri &a,const tri &b)->ll{
            return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
        };
        
        sort(vp.begin()+1,vp.end(),[&ccw,&dist,&vp](const tri &a,const tri &b)->bool{
            int tmp=ccw(vp.front(),a,b);
            return tmp<0||(tmp==0&&dist(vp[0],a)<dist(vp[0],b));
        });
        
        int it=n-1;
        while(ccw(vp.front(),vp[it],vp[it-1])==0)it--;
        reverse(vp.begin()+it,vp.end());
        
        for(auto &t:vp)cout<<t[2]<<" ";
        cout<<"\n";
    }
    return 0;
}
