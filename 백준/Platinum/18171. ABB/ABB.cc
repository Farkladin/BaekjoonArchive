#include "bits/stdc++.h"
using namespace std;

vector<int>Manacher(string s){
    string T="@";
    for(auto c:s){
        T.push_back(c);
        T.push_back('@');
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
    string s;cin>>s;
    auto R=Manacher(s);
    int ans=2e9;
    for(int i=N*2;i>=0;i--){
        if(i+R[i]==N*2)ans=min(ans,(i-R[i])>>1);
    }
    cout<<ans<<"\n";

    return 0;
}
