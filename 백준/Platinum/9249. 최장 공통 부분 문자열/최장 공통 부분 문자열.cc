#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;

vector<int>sa(string s){
    s.push_back('!');
    const int n=(int)s.size();
    vector<int>p(n),c(n);
    vector<pair<char,int> >vp(n);
    for(int i=0;i<n;i++)vp[i]={s[i],i};
    sort(vp.begin(),vp.end());
    for(int i=0;i<n;i++)p[i]=vp[i].se;
    c[p[0]]=0;
    
    for(int i=1;i<n;i++){
        if(vp[i].fi==vp[i-1].fi){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
    
    for(int k=1;k<n;k<<=1){
        vector<array<int,3> >va(n);
        for(int i=0;i<n;i++){
            va[i]={c[i],c[(i+k)%n],i};
        }
        sort(va.begin(),va.end());
        
        for(int i=0;i<n;i++)p[i]=va[i][2];
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(va[i][0]==va[i-1][0]&&va[i][1]==va[i-1][1]){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
    }
    
    return vector<int>(p.begin()+1,p.end());
}


void solve9249(vector<int>&sa,string s,const int len){
    const int n=(int)sa.size();
    vector<int>pi(n),arr(n);
    for(int i=0;i<n;i++)pi[sa[i]]=i;
    
    int ans1=0,idx=0;
    for(int i=0,k=0;i<n-1;i++){
        if(pi[i]){
            int j=sa[pi[i]-1];
            while(s[i+k]==s[j+k])k++;
            arr[pi[i]]=k;
            if(k>ans1&&min(i,j)<len&&max(i,j)>len){
                ans1=k;
                idx=i;
            }
            k=max(k-1,0);
        }
    }
    cout<<ans1<<"\n"<<string(s.begin()+idx,s.begin()+idx+ans1)<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string T,S;cin>>T>>S;
    int tmp=(int)T.size();
    T=T+"|"+S;
    auto arr=sa(T);
    solve9249(arr,T,tmp);
    return 0;
}
