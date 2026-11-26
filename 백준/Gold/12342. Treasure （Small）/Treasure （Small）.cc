#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
int arr[23],N;
vector<int>vi,ans,brr[23];
unordered_map<string,bool>memo;
array<int,20>cnt;
string hashing(int bit){
    string ret=to_string(bit);
    for(int i=0;i<20;i++){
        ret.push_back('?');
        ret+=to_string(cnt[i]);
    }
    return ret;
}
bool found=false;
void f(int bit){
    string s=hashing(bit);
    if(memo[s])return;
    memo[s]=true;
    if(found)return;
    if(vi.size()==N){
        ans=vi;
        found=true;
    }

    for(int i=0;i<N;i++){
        if((bit&(1<<i))==0&&cnt[arr[i]]>0){
            vi.push_back(i);
            cnt[arr[i]]--;
            for(int k:brr[i]){
                cnt[k]++;
            }
            f(bit|(1<<i));
            for(int k:brr[i]){
                cnt[k]--;
            }
            cnt[arr[i]]++;
            vi.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int K;cin>>K>>N;
        for(int i=0;i<=N;i++)brr[i].clear();
        vector<int>crr[23];
        memset(arr,0,sizeof(arr));
        
        ans.clear();
        vi.clear();
        fill(cnt.begin(),cnt.end(),0);
        memo.clear();
        
        vector<int>mp(203,-1);
        vector<int>keys(K);
        int idx=0;
        for(int i=0;i<K;i++)cin>>keys[i];
        for(int i=0;i<N;i++){
            int t,k;cin>>t>>k;
            if(mp[t]==-1)mp[t]=idx++;
            arr[i]=mp[t];
            while(k--){
                int x;cin>>x;
                crr[i].push_back(x);
            }
        }
        for(int i=0;i<N;i++){
            for(int x:crr[i]){
                if(mp[x]!=-1)brr[i].push_back(mp[x]);
            }
        }
        
        for(int x:keys){
            if(mp[x]!=-1)cnt[mp[x]]++;
        }
        cout<<format("Case #{:d}: ",tc);
        found=false;
        f(0);
        if(!found)cout<<"IMPOSSIBLE\n";
        else{
            for(auto a:ans)cout<<a+1<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
