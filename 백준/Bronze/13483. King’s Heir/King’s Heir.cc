#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int d,m,y;cin>>d>>m>>y;
    int a=0,b=0,c=0,idx=-1;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int di,mi,yi;cin>>di>>mi>>yi;
        if(yi+18>y)continue;
        if(yi+18==y){
            if(mi>m)continue;
            else if(mi==m){
                if(di>d)continue;
            }
        }
        if(yi>c || (yi==c&&mi>b) || (yi==c&&mi==b&&di>a)){
            a=di;
            b=mi;
            c=yi;
            idx=i;
        }
    }
    cout<<idx<<"\n";
    return 0;
}
