#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    
    vector<pii>vp;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        char c;cin>>c;
        if(c=='Y')vp.push_back({x,y});
    }
    n=(int)vp.size();
    
    sort(vp.begin(),vp.end(),[](const pii &a,const pii &b)->bool{
        return a.fi<b.fi||(a.fi==b.fi&&a.se<b.se);
    });
    
    auto ccw=[&vp](const pii &a,const pii &b,const pii &c)->int{
        ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
        if(cp>0)return 1;
        if(cp<0)return -1;
        return 0;
    };
    
    auto dist=[](const pii &a,const pii &b)->ll{
        return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
    };
    
    sort(vp.begin()+1,vp.end(),[&ccw,&dist,&vp](const pii &a,const pii &b)->bool{
        int tmp=ccw(vp.front(),a,b);
        return tmp<0||(tmp==0&&dist(vp[0],a)<dist(vp[0],b));
    });
        
    int it=n-1;
    while(ccw(vp.front(),vp[it],vp[it-1])==0)it--;
    reverse(vp.begin()+it,vp.end());
    reverse(vp.begin()+1,vp.end());
    cout<<n<<"\n";
    for(auto &t:vp)cout<<t.fi<<" "<<t.se<<"\n";
    cout<<"\n";
    return 0;
}
