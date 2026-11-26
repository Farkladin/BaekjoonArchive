#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

template<ll p,ll R,ll N>
class NTT{
    const ll modinvR,modinvN;
    
public:
    ll po(ll a,ll b){
        ll ret=1;
        while(b){
            if(b&1)ret=ret*a%p;
            a=a*a%p;b>>=1;
        }
        return ret;
    }
    
    NTT():modinvR(po(R,p-2)),modinvN(po(N,p-2)){}
    
    void FFT(vector<ll>&a){
        ll i,j,k,x,y,z,t;
        for(i=1,j=0;i<N;i++){
            for(k=N>>1;k<=j;k>>=1)j-=k;
            j+=k;
            if(i<j)swap(a[i],a[j]);
        }
        for(i=1,t=1;i<N;i<<=1,t++){
            x=po(R,p>>t);
            for(j=0;j<N;j+=i<<1){
                y=1;
                for(k=0;k<i;k++){
                    z=a[i|j|k]*y%p;
                    a[i|j|k]=(a[j|k]-z+p)%p;
                    a[j|k]=(a[j|k]+z)%p;
                    y=y*x%p;
                }
            }
        }
    }
    
    void iFFT(vector<ll>&a){
        ll i,j,k,x,y,z,t;
        for(i=1,j=0;i<N;i++){
            for(k=N>>1;k<=j;k>>=1)j-=k;
            j+=k;
            if(i<j)swap(a[i],a[j]);
        }
        for(i=1,t=1;i<N;i<<=1,t++){
            x=po(modinvR,p>>t);
            for(j=0;j<N;j+=i<<1){
                y=1;
                for(k=0;k<i;k++){
                    z=a[i|j|k]*y%p;
                    a[i|j|k]=(a[j|k]-z+p)%p;
                    a[j|k]=(a[j|k]+z)%p;
                    y=y*x%p;
                }
            }
        }
        for(i=0;i<N;i++)a[i]=a[i]*modinvN%p;
    }
};

constexpr ll nttN=65536;
constexpr ll p=104857601;
NTT<p,3,nttN>X;
vector<ll> operator*(vector<ll>a,vector<ll>b){
    X.FFT(a);X.FFT(b);
    for(int i=0;i<nttN;i++){
        a[i]=a[i]*b[i]%p;
    }
    X.iFFT(a);
    return a;
}

vector<ll> operator-(const vector<ll> &ref){
    vector<ll>ret(ref.begin(),ref.end());
    for(int i=1;i<nttN;i+=2)ret[i]=(p-ret[i])%p;
    return ret;
}

vector<ll>BMsub(const vector<ll>&ref,const int isOdd=0){
    vector<ll>ret(nttN);
    int k=0;
    for(int i=isOdd;i<nttN;i+=2)ret[k++]=ref[i];
    return ret;
}

ll BostanMori(ll N,vector<ll>P,vector<ll>Q){
    while(N){
        vector<ll>mQ=-Q;
        vector<ll>U=P*mQ;
        P=BMsub(U,N&1);
        Q=BMsub(Q*mQ);
        N>>=1;
    }
    return P[0]*X.po(Q[0],p-2)%p;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int k;ll N;cin>>k>>N;
    vector<ll>P(nttN),Q(nttN);
    for(int i=0;i<k;i++)cin>>P[i];
    Q[0]=1;
    for(int i=1;i<=k;i++){
        cin>>Q[i];
        Q[i]=(p-Q[i])%p;
    }
    P=P*Q;
    for(int i=k;i<nttN;i++)P[i]=0;
    ll ans=BostanMori(N-1,P,Q)%p;
    cout<<ans<<"\n";
    return 0;
}
