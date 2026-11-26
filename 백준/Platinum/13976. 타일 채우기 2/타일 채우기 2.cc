#include "bits/stdc++.h"
using namespace std;
using ll=long long;

template<class T,
ll mod>
class mat{
    vector<vector<T> >arr;
    int n,m;
    
public:
    mat(int N=0,int M=0):n(N),m(M),arr(vector<vector<T> >(N,vector<T>(M))){}
    mat(const vector<vector<T> > init){
        arr=init;
        n=arr.size();
        if(!arr.empty()) m=arr.back().size();
        else m=0;
    }
    
    int size(){
        return n;
    }
    
    const T& operator()(const int i,const int j)const{
        return arr[i][j];
    }
    
    T& operator()(const int i,const int j){
        return arr[i][j];
    }
    
    mat& operator*=(const mat &rhs){
        mat tmp=mat<T, mod>(n, rhs.m);
        for(int i=0;i<n;i++){
            for(int j=0;j<rhs.m;j++){
                tmp(i,j)=0;
                for(int k=0;k<m;k++){
                    tmp(i,j)=(mod+tmp(i,j)+arr[i][k]*rhs(k,j))%mod;
                }
            }
        }
        this->arr=tmp.arr;
        return *this;
    }
    
    mat operator*(const mat &rhs){
        mat tmp=mat<T, mod>(n, rhs.m);
        for(int i=0;i<n;i++){
            for(int j=0;j<rhs.m;j++){
                tmp(i,j)=0;
                for(int k=0;k<m;k++){
                    tmp(i,j)=(mod+tmp(i,j)+arr[i][k]*rhs(k,j))%mod;
                }
            }
        }
        return tmp;
    }
};


using Mat=mat<ll,1'000'000'007>;
Mat po(Mat a,ll b){
    Mat ret(a.size(),a.size());
    for(int i=0;i<ret.size();++i) ret(i,i)=1;
    while(b){
        if(b&1)ret=ret*a;
        b>>=1;a=a*a;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Mat A(vector<vector<ll> >({
        {4,-1},
        {1,0}
        }));
    Mat B(vector<vector<ll> >({
        {3},
        {1}
        }));
    
    ll D; cin>>D;
    if(D&1){
        cout<<"0\n";
        return 0;
    }
    
    A=po(A,D>>1)*B;
    
    cout<<A(1,0)<<"\n";
    return 0;
}
