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

constexpr ll arr[10][10]={
    {0,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {0,1,0,1,0,0,1,1},
    {0,0,1,0,1,0,1,0},
    {0,0,0,1,0,1,0,0},
    {0,0,0,0,1,0,1,0},
    {0,0,1,1,0,1,0,1},
    {1,1,1,0,0,0,1,0}
};

using Mat=mat<ll,1'000'000'007>;
Mat po(Mat a,ll b){
    Mat ret(a.size());
    while(b){
        if(b&1)ret=ret*a;
        b>>=1;a=a*a;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Mat A(8);
    
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            A(i,j)=arr[i][j];
        }
    }
    
    ll D; cin>>D;
    A=po(A,D);
    
    cout<<A(0,0)<<"\n";
    return 0;
}
