#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;
char arr[10][10];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(arr[i][j]>'9')arr[i][j]=-arr[i][j]+'A'-1;
            else arr[i][j]-='0';
        }
    }
    vector<int>vi(N);
    for(int i=0;i<N;i++)vi[i]=i;
    int mn=2e9,mx=-2e9;
    for(int i=0;i<720;i++){
        vector<bool>vis(N);
        int cur=1,cnt=0;
        for(int j=0;j<N;j++){
            if(vis[j])continue;
            vis[j]=true;
            cur*=arr[j][vi[j]];
            cnt++;
            int u=j;
            while(!vis[vi[u]]){
                u=vi[u];
                cur*=arr[u][vi[u]];
                vis[u]=true;
            }
        }
        if((cnt&1)==0)cur=-cur;
        mn=min(mn,cur);
        mx=max(mx,cur);
        next_permutation(vi.begin(),vi.end());
    }
    cout<<mn<<"\n"<<mx<<"\n";
    return 0;
}

