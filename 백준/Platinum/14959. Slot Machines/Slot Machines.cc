#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

vector<int>cpf(vector<int>&s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<int>arr(n);
    for(auto &a:arr)cin>>a;
    reverse(arr.begin(),arr.end());
    auto pf=cpf(arr);
    pair<int,int>ans={1e8,1e8};
    for(int i=0;i<n;i++){
        int x=n-i-1,y=i-pf[i]+1;
        if(x+y<ans.fi+ans.se||(x+y==ans.fi+ans.se&&y<ans.se)){
            ans={x,y};
        }
    }
    cout<<ans.fi<<" "<<ans.se<<"\n";
    return 0;
}
