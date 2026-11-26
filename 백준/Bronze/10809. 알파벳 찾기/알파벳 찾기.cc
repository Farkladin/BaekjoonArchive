#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int>arr(256,-1);
    string s;cin>>s;
    for(int i=0;i<(int)s.size();i++){
        if(arr[s[i]]==-1){
            arr[s[i]]=i;
        }
    }
    for(int i='a';i<='z';i++)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
