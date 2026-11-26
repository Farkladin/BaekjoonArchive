#include "bits/stdc++.h"
using namespace std;
int S[303],W[303],N;
int f(int idx){
    if(idx>N){
        int ret=0;
        for(int i=1;i<=N;i++){
            if(S[i]<=0)ret++;
        }
        return ret;
    }
    int mx=0;
    if(S[idx]<=0)return f(idx+1);
    bool flag=false;
    for(int i=1;i<=N;i++){
        if(S[i]<=0||i==idx)continue;
        flag=true;
        S[i]-=W[idx];
        S[idx]-=W[i];
        mx=max(mx,f(idx+1));
        S[i]+=W[idx];
        S[idx]+=W[i];
    }
    if(!flag)mx=max(mx,f(idx+1));
    return mx;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>S[i]>>W[i];
    }
    cout<<f(1)<<"\n";
    return 0;
}
