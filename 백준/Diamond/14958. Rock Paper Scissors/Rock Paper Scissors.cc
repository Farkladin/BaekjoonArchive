#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll p=(17LL<<27)|1,R=3,N=(1<<18);
ll po(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;b>>=1;
    }
    return ret;
}

constexpr ll modinvR=760567126; // modinvR=po(R,p-2);
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
    const ll modinvN=po(N,p-2);
    for(i=0;i<N;i++)a[i]=a[i]*modinvN%p;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int gar1,gar2; cin>>gar1>>gar2;
    string S,T;cin>>S>>T;
    const int n=(int)S.size(),m=(int)T.size();
    vector<ll>X1(N),Y1(N),X2(N),Y2(N),X3(N),Y3(N);
    for(int i=0;i<n;i++){
        X1[i]=S[i]=='R';
        X2[i]=S[i]=='S';
        X3[i]=S[i]=='P';
    }
    reverse(T.begin(),T.end());
    for(int i=0;i<m;i++){
        Y1[i]=T[i]=='P';
        Y2[i]=T[i]=='R';
        Y3[i]=T[i]=='S';
    }
    FFT(X1);FFT(Y1);FFT(X2);FFT(Y2);FFT(X3);FFT(Y3);
    for(int i=0;i<N;i++){
        X1[i]=X1[i]*Y1[i]%p;
        X2[i]=X2[i]*Y2[i]%p;
        X3[i]=X3[i]*Y3[i]%p;
    }
    iFFT(X1);iFFT(X2);iFFT(X3);
    ll ans=0;
    for(int i=m-1;i<n+m-1;i++){
        ans = max(ans,X1[i] + X2[i] + X3[i]);
    }
    cout<<ans<<"\n";
    
    return 0;
}
