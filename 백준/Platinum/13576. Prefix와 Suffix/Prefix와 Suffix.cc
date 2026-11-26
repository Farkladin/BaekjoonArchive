#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

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


vector<int>lcpa(vector<int>&sa,string s){
    const int n=(int)sa.size();
    vector<int>pi(n),arr(n);
    for(int i=0;i<n;i++)pi[sa[i]]=i;
    for(int i=0,k=0;i<n-1;i++){
        if(pi[i]){
            int j=sa[pi[i]-1];
            while(s[i+k]==s[j+k])k++;
            arr[pi[i]]=k;
            k=max(k-1,0);
        }
    }
    return arr;
}

vector<int>Z(string s){
    const int n=(int)s.size();
    vector<int>z(n);z[0]=n;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<r)z[i]=min(r-i,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string S;cin>>S;
    auto sarr=sa(S);
    auto lcparr=lcpa(sarr,S);
    const int n=(int)S.size();
    stack<pair<int,int> >stk;stk.push({sarr.front(),0});
    vector<pair<int,int> >vp;
    for(int i=1;i<n;i++){
        while(!stk.empty()&&n-stk.top().fi>lcparr[i]){
            auto [x,y]=stk.top();stk.pop();
            vp.push_back({-x,i-y});
        }
        stk.push({sarr[i],i});
    }
    while(!stk.empty()){
        auto [x,y]=stk.top();stk.pop();
        vp.push_back({-x,n-y});
    }
    auto zrr=Z(S);
    sort(vp.begin(),vp.end());
    int cnt=0;
    stringstream ss;
    for(auto p:vp){
        if(zrr[-p.fi]==n+p.fi){
            cnt++;
            ss<<n+p.fi<<" "<<p.se<<"\n";
        }
    }
    cout<<cnt<<"\n";
    string tmp;
    while(getline(ss,tmp))cout<<tmp<<"\n";
    return 0;
}
