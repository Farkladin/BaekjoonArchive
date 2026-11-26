#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
struct ff{
    lf x,y,z,vx,vy,vz;
    ff(lf x=0,lf y=0,lf z=0,lf vx=0,lf vy=0,lf vz=0):x(x),y(y),z(z),vx(vx),vy(vy),vz(vz){}
};
vector<ff>arr;
lf g(lf t){
    lf xc=0,yc=0,zc=0,n=(lf)arr.size();
    for(ff &u:arr){
        xc+=u.x+u.vx*t;
        yc+=u.y+u.vy*t;
        zc+=u.z+u.vz*t;
    }
    xc/=n;
    yc/=n;
    zc/=n;

    return sqrt(xc*xc+yc*yc+zc*zc);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;cin>>N;
        arr.clear();
        arr.resize(N);
        lf scx=0,scy=0,scz=0,svx=0,svy=0,svz=0;
        for(int i=0;i<N;i++){
            ff &a=arr[i];
            cin>>a.x>>a.y>>a.z>>a.vx>>a.vy>>a.vz;
            scx+=a.x;scy+=a.y;scz+=a.z;
            svx+=a.vx;svy+=a.vy;svz+=a.vz;
        }
        lf t=0;
        if((svx*svx+svy*svy+svz*svz)>=1e-14)t=max(-(scx*svx+scy*svy+scz*svz)/(svx*svx+svy*svy+svz*svz),0.0)+1e-12;
        cout<<format("Case #{:d}: {:.10f} {:.10f}",tc,g(t),t)<<"\n";
    }
    return 0;
}
