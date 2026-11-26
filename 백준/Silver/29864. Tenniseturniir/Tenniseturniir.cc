#include "bits/stdc++.h"
using namespace std;
int cnt[14],arr[14];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=8;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=7;i++){
        int a;cin>>a;
        cnt[a]++;
    }
    stack<vector<int> >ans;
    for(int k=8;k>1;k>>=1){
        vector<int>tmp;
        for(int i=1,j=1;i<=k;i+=2,j++){
            if(cnt[arr[i]])arr[j]=arr[i];
            else arr[j]=arr[i+1];
            cnt[arr[j]]--;
            tmp.push_back(arr[j]);
        }
        ans.push(tmp);
    }
    while(!ans.empty()){
        for(int x:ans.top())cout<<x<<" ";
        cout<<"\n";
        ans.pop();
    }
    return 0;
}
