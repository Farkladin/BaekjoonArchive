#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod=1234567891;
set<int>arr[10][10];
template<class T>
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

mat<ll>po(mat<ll>a,ll b){
    mat<ll>ret(2);
    while(b){
        if(b&1)ret=ret*a;
        a=a*a;b>>=1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,L;cin>>N>>L;
    
    for(int i=1;i<=N;i++){
        string s;cin>>s;
        bool flag=true;
        for(char c:s){
            if(c!='7'&&c!='4'){
                flag=false;
            }
        }
        if(flag)arr[s.front()-'0'][s.back()-'0'].insert(stoi(s));
    }
    
    ll c44=(int)arr[4][4].size(),c47=(int)arr[4][7].size(),c74=(int)arr[7][4].size(),c77=(int)arr[7][7].size();
    mat<ll>A(2);
    A(0,0)=c44;
    A(0,1)=c74;
    A(1,0)=c47;
    A(1,1)=c77;
    A=po(A,L-1);
    ll d4=(c44+c74)%mod,d7=(c77+c47)%mod;
    cout<<(d4*A(0,0)%mod+d4*A(1,0)%mod+d7*A(0,1)%mod+d7*A(1,1)%mod)%mod<<"\n";
    return 0;
}
