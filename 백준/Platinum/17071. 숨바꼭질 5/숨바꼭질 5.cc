#include "bits/stdc++.h"
using namespace std;
int arr[500003][2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    fill(&arr[0][0],&arr[0][0]+1000006,1e9);
    
    arr[N][1]=1;
    queue<pair<int,int> >q;q.push({N,1});
    while(!q.empty()){
        auto [u,x] = q.front(); q.pop();
        if(u<500000 && arr[u+1][x^1]>arr[u][x]+1){
            arr[u+1][x^1]=arr[u][x]+1;
            q.push({u+1,x^1});
        }
        if(u>0 && arr[u-1][x^1]>arr[u][x]+1){
            arr[u-1][x^1]=arr[u][x]+1;
            q.push({u-1,x^1});
        }
        if(2*u<=500000 && arr[2*u][x^1]>arr[u][x]+1){
            arr[2*u][x^1]=arr[u][x]+1;
            q.push({2*u,x^1});
        }
    }
    
    int t=1;
    while(K<=500000){
        if(arr[K][t&1]<=t){
            cout<<t-1<<"\n";
            return 0;
        }
        K+=t++;
    }
    cout<<"-1\n";
    return 0;
}
