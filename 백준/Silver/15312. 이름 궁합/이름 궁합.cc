#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr int asset[]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string A,B;cin>>A>>B;
    vector<int>arr;
    for(int i=0;i<(int)A.size();i++){
        arr.push_back(asset[A[i]-'A']);
        arr.push_back(asset[B[i]-'A']);
    }
    for(int j=2;j<(int)arr.size();j++){
        for(int i=0;i<(int)arr.size()-1;i++){
            arr[i]=(arr[i]+arr[i+1])%10;
        }
    }
    cout<<arr[0]<<arr[1]<<"\n";
    return 0;
}
