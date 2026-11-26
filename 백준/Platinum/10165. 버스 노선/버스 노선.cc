#include "bits/stdc++.h"
using namespace std;

struct Type{
    int a,b,idx;
    bool operator<(const Type &rhs) const{
        return a<rhs.a || (a==rhs.a && b>rhs.b);
    }
}arr[1'000'003];

bool vis[500'003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,M; cin>>N>>M;
    
    int cnt=0;
    for(int i=1; i<=M; ++i){
        cin>>arr[i].a>>arr[i].b;
        arr[i].idx=i;
        if(arr[i].a>arr[i].b)arr[i].b+=N;
        else{
            ++cnt;
            arr[M+cnt].a=arr[i].a+N;
            arr[M+cnt].b=arr[i].b+N;
            arr[M+cnt].idx=i;
        }
    }
    
    sort(arr+1,arr+1+M+cnt);
    int last=-2e9;
    vector<int>ans;
    for(int i=1; i<=M+cnt; ++i){
        if(arr[i].b > last){
            last=arr[i].b;
        }else{
            vis[arr[i].idx]=true;
        }
    }
    
    sort(ans.begin(),ans.end());
    for(int i=1; i<=M; ++i){
        if(!vis[i])cout<<i<<" ";
    }
    cout<<"\n";
    
    return 0;
}
