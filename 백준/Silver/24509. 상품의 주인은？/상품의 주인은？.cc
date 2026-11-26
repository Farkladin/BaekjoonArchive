#include "bits/stdc++.h"
#include <format>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<array<int,5> >va(N+3);
    for(int i=1;i<=N;i++){
        cin>>va[i][0]>>va[i][1]>>va[i][2]>>va[i][3]>>va[i][4];
    }
    sort(va.begin()+1,va.begin()+N+1);
    int mx,idx;
    mx=idx=-1e9;
    for(int i=1;i<=N;i++){
        if(mx<va[i][1]){
            mx=va[i][1];
            idx=i;
        }
    }
    cout<<va[idx][0]<<" ";
    va[idx]={-1,-1,-1,-1,-1};
    mx=idx=-1e9;
    for(int i=1;i<=N;i++){
        if(mx<va[i][2]){
            mx=va[i][2];
            idx=i;
        }
    }
    cout<<va[idx][0]<<" ";
    va[idx]={-1,-1,-1,-1,-1};
    mx=idx=-1e9;
    for(int i=1;i<=N;i++){
        if(mx<va[i][3]){
            mx=va[i][3];
            idx=i;
        }
    }
    cout<<va[idx][0]<<" ";
    va[idx]={-1,-1,-1,-1,-1};
    mx=idx=-1e9;
    for(int i=1;i<=N;i++){
        if(mx<va[i][4]){
            mx=va[i][4];
            idx=i;
        }
    }
    cout<<va[idx][0]<<"\n";
    va[idx]={-1,-1,-1,-1,-1};
    return 0;
}
