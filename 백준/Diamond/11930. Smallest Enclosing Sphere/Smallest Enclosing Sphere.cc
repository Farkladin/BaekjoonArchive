#include "bits/stdc++.h"
using namespace std;

using lf=double;
using tri=array<lf,3>;
inline lf dist(const tri &a,const tri b){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])+(a[2]-b[2])*(a[2]-b[2]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    lf x=0,y=0,z=0;
    vector<tri>arr(N);
    for(auto &t:arr){
        cin>>t[0]>>t[1]>>t[2];
        x+=t[0];
        y+=t[1];
        z+=t[2];
    }
    z/=N;
    y/=N;
    x/=N;
    lf T=0.1,ans=1e18;
    for(int i=0;i<200000;i++){
        tri *mx=&arr.front();
        lf mxr=0;
        for(auto &t:arr){
            lf cur=dist(t,tri({x,y,z}));
            if(cur>mxr){
                mxr=cur;
                mx=&t;
            }
        }
        ans=min(ans,mxr);
        x+=((*mx)[0]-x)*T;
        y+=((*mx)[1]-y)*T;
        z+=((*mx)[2]-z)*T;
        T*=0.999;
    }
    cout<<fixed<<setprecision(2)<<sqrt(ans)<<"\n";
    return 0;
}
