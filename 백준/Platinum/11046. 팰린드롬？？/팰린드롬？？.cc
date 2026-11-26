#include "bits/stdc++.h"
using namespace std;
using ll=long long;

vector<int>Manacher(vector<int>&s){
    vector<int>T={-1};
    for(auto c:s){
        T.push_back(c);
        T.push_back(-1);
    }
    const int n=(int)T.size();
    int r=0,p=0;
    vector<int>arr(n+3);
    for(int i=0;i<n;i++){
        if(i<=r)arr[i]=min(arr[2*p-i],r-i);else arr[i]=0;
        while(i-arr[i]-1>=0&& i+arr[i]+1<n&&T[i-arr[i]-1]==T[i+arr[i]+1])arr[i]++;
        if(arr[i]+i>r){
            r=arr[i]+i;
            p=i;
        }
    }
    return arr;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>T(N);
    for(auto &c:T)cin>>c;
    vector<int>arr=Manacher(T);
    int M;cin>>M;
    while(M--){
        int S,E;cin>>S>>E;
        cout<<(arr[S+E-1]>=E-S+1)<<"\n";
    }
    return 0;
}
