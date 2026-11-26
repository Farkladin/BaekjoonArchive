#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed;
    cout.precision(5);
    int tc=0;
    while(1){
        tc++;
        int N;cin>>N;
        if(N==-1)break;
        vector<double>vd(15);
        for(int i=1;i<=N;i++){
            int x;double y;cin>>x>>y;
            vd[x]=y;
        }
        int X;double Y;cin>>X>>Y;
        cout<<"Case "<<tc<<": ";
        double l=0,r=1;
        for(int i=1;i<=1000;i++){
            double mid=(l+r)*0.5;
            double cur=0,k=mid+1;
            for(int j=X;j>0;j--){
                cur+=k*vd[j];
                k*=mid+1;
            }
            if(cur>Y)r=mid;
            else l=mid;
        }
        cout<<l<<"\n\n";
    }
    return 0;
}
