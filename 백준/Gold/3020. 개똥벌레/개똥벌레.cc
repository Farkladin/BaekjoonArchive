#include "bits/stdc++.h"
using namespace std;
int B[500003],T[500003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,H;cin>>N>>H;
    B[1]=T[H]=N>>1;
    for(int i=1;i<=(N>>1);i++){
        int x,y;cin>>x>>y;
        B[x+1]--;
        T[H-y]--;
    }
    for(int i=2;i<=H;i++)B[i]+=B[i-1];
    for(int i=H-1;i>0;i--)T[i]+=T[i+1];
    int mn=1e9,cnt=0;
    for(int i=1;i<=H;i++){
        if(B[i]+T[i]<mn){
            mn=B[i]+T[i];
            cnt=0;
        }
        if(B[i]+T[i]==mn){
            cnt++;
        }
    }
    cout<<mn<<" "<<cnt<<"\n";
    return 0;
}
