#include "bits/stdc++.h"
using namespace std;
vector<vector<int> >arr,brr;
vector<int>tmp={1};
int A[23][11],S[23][11];
void f(int i,int n,int k,vector<vector<int> >&vv){
    if(i>n)return;
    if(tmp.size()==k){
        tmp.push_back(n+1);
        vv.push_back(tmp);
        tmp.pop_back();
        return;
    }
    for(int j=i+1;j<=n;j++){
        tmp.push_back(j);
        f(j,n,k,vv);
        tmp.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,a,b;cin>>n>>m>>a>>b;
    f(1,n,a+1,arr);
    f(1,m,b+1,brr);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>A[i][j];
            S[i][j]=S[i][j-1]+A[i][j];
        }
    }
    int ans=1e9;
    for(vector<int>&av:arr){
        for(vector<int>&bv:brr){
            int cur=0;
            for(int ai=0;ai<=a;ai++){
                for(int bi=0;bi<=b;bi++){
                    int tmp=0;
                    for(int i=av[ai];i<av[ai+1];i++){
                        tmp+=S[i][bv[bi+1]-1]-S[i][bv[bi]-1];
                    }
                    cur=max(cur,tmp);
                    if(cur>ans)goto skip;
                }
            }
            skip:
            ans=min(ans,cur);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
