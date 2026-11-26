#include "bits/stdc++.h"
using namespace std;
using ll=long long;

template<class T,
ll mod>
class mat{
    vector<vector<T> >arr;
    int n;
    
public:
    mat(int N=0):n(N),arr(vector<vector<T> >(N,vector<T>(N))){
        for(int i=0;i<n;i++)arr[i][i]=1;
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
        mat tmp=*this;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp(i,j)=0;
                for(int k=0;k<n;k++){
                    tmp(i,j)=(tmp(i,j)+arr[i][k]*rhs(k,j))%mod;
                }
            }
        }
        this->arr=tmp.arr;
        return *this;
    }
    
    mat operator*(const mat &rhs){
        mat tmp=*this;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp(i,j)=0;
                for(int k=0;k<n;k++){
                    tmp(i,j)=(tmp(i,j)+arr[i][k]*rhs(k,j))%mod;
                }
            }
        }
        return tmp;
    }
};

using Mat = mat<ll, 1'000'000'007>;

Mat po(Mat a,int b){
    Mat ret(a.size());
    while(b){
        if(b&1)ret=ret*a;
        a=a*a; b>>=1;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T,N,D; cin>>T>>N>>D;
    Mat A(N);
    vector<Mat>vec;
    for(int i=1; i<=T; ++i){
        vec.emplace_back(N);
        for(int j=0; j<N; ++j)vec.back()(j,j)=0;
        int M; cin>>M;
        while(M--){
            int a,b,c; cin>>a>>b>>c;
            vec.back()(a-1,b-1)+=c;
        }
        A*=vec.back();
    }
    
    A=po(A,D/T); D%=T;
    for(int i=0; i<D; ++i){
        A*=vec[i];
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j)cout<<A(i,j)<<" ";
        cout<<"\n";
    }
    
    return 0;
}
