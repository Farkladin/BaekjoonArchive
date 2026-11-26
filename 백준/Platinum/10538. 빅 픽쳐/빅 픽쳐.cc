#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ull=uint64_t;
constexpr ull p1=2147483647,p2=998244353,q1=101,q2=74747;

template<ull mod>
ull po(ull a,ull b){
    ull ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

vector<int>cpf(vector<pair<ull,ull> >&s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

int kmp(vector<pair<ull,ull> >&T,vector<pair<ull,ull> >&P){
    vector<int>nxt(cpf(P));
    int ans=0;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m){
            ans++;
            j=nxt[j-1];
        }
    }
    return ans;
}

int mp[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int hp,wp,hm,wm;cin>>hp>>wp>>hm>>wm;
    vector<pair<ull,ull> >arr(hp),brr(hm);
    mp['o']=0;
    mp['x']=1;
    for(auto &p:arr){
        string s;cin>>s;
        ull &a=p.fi,&b=p.se;
        for(auto c:s){
            a=(a*q1%p1+mp[c])%p1;
            b=(b*q2%p2+mp[c])%p2;
        }
    }
    
    vector<string>vs(hm);
    for(int i=0;i<hm;i++){
        cin>>vs[i];
        ull &a=brr[i].fi,&b=brr[i].se;
        for(int j=0;j<wp;j++){
            a=(a*q1%p1+mp[vs[i][j]])%p1;
            b=(b*q2%p2+mp[vs[i][j]])%p2;
        }
    }
    
    int ans=kmp(brr,arr);
    for(int i=1;i+wp<=wm;i++){
        for(int j=0;j<hm;j++){
            auto &p=brr[j];
            p.fi=((p.fi+p1-po<p1>(q1,wp-1)*mp[vs[j][i-1]])%p1*q1%p1+mp[vs[j][i+wp-1]])%p1;
            p.se=((p.se+p2-po<p2>(q2,wp-1)*mp[vs[j][i-1]])%p2*q2%p2+mp[vs[j][i+wp-1]])%p2;
        }
        ans+=kmp(brr,arr);
    }
    cout<<ans<<"\n";
    return 0;
}
