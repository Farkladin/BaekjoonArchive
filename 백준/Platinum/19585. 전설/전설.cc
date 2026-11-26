#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
constexpr ull p1=2147483647,p2=4294967291,q1=101,q2=74747,p=67280421310721;

ull po(ull a,ull b,const ull &mod){
    ull ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
ull po1[2003]={1},po2[3003]={1};

class hasher{
    ull val1,val2,n;
    
public:
    
    static ull f(ull a,ull b){
        return (a*11%p+b*121%p)%p;
    }
    
    ull val;
    hasher(){}
    hasher(string s){
        val=0;
        val1=0;
        val2=0;
        n=(ull)s.size();
        for(auto c:s){
            val1=((c-'a'+1)+val1*q1)%p1;
            val2=((c-'a'+1)+val2*q2)%p2;
        }
        val=f(val1,val2);
    }
    hasher operator+(const hasher &ref){
        hasher ret;
        ret.val1=(val1*po1[ref.n]+ref.val1)%p1;
        ret.val2=(val2*po2[ref.n]+ref.val2)%p2;
        ret.val=f(ret.val1,ret.val2);
        ret.n=n+ref.n;
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=2000;i++){
        po1[i]=po1[i-1]*q1%p1;
        po2[i]=po2[i-1]*q2%p2;
    }
    int C,N;cin>>C>>N;
    unordered_set<ull>suff,pref;
    for(int i=0;i<C;i++){
        string s;cin>>s;
        pref.insert(hasher(s).val);
    }
    for(int i=0;i<N;i++){
        string s;cin>>s;
        suff.insert(hasher(s).val);
    }
    
    int Q;cin>>Q;
    while(Q--){
        string s;cin>>s;
        ull val1=0,val2=0;
        const int n=(int)s.size();
        vector<ull>arr(n);
        for(int i=n-1;i>=0;i--){
            val1=(val1+(s[i]-'a'+1)*po1[n-i-1])%p1;
            val2=(val2+(s[i]-'a'+1)*po2[n-i-1])%p2;
            arr[i]=hasher::f(val1,val2);
        }
        val1=0;val2=0;
        for(int i=0;i<n;i++){
            val1=((s[i]-'a'+1)+val1*q1)%p1;
            val2=((s[i]-'a'+1)+val2*q2)%p2;
            ull val=hasher::f(val1,val2);
            if(pref.find(val)!=pref.end()){
                if(suff.find(arr[i+1])!=suff.end()){
                    cout<<"Yes\n";
                    goto YES;
                }
            }
        }
        cout<<"No\n";
        YES:
    }
    return 0;
}
