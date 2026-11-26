#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using tri=array<ll,3>;
struct S{
    ll x,y,z;
    int n;
}arr[100003];
vector<tri>edges;
class ds{
public:
    vector<int>pos;
    ds(){
        pos.resize(100003);
        for(int i=1;i<=100000;i++)pos[i]=i;
    }
    int find(int x){
        int z=x;
        while(z!=pos[z])z=pos[z];
        while(x!=pos[x]){
            int tmp=x;
            x=pos[x];
            pos[tmp]=z;
        }
        return z;
    }
    void uni(int x,int y){
        x=find(x);
        y=find(y);
        pos[y]=x;
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].z;
        arr[i].n=i;
    }
    sort(arr+1,arr+1+N,[](const S &a,const S &b)->bool{
        return a.x<b.x;
    });
    for(int i=2;i<=N;i++){
        edges.push_back({arr[i-1].n,arr[i].n,arr[i].x-arr[i-1].x});
    }
    sort(arr+1,arr+1+N,[](const S &a,const S &b)->bool{
        return a.y<b.y;
    });
    for(int i=2;i<=N;i++){
        edges.push_back({arr[i-1].n,arr[i].n,arr[i].y-arr[i-1].y});
    }
    sort(arr+1,arr+1+N,[](const S &a,const S &b)->bool{
        return a.z<b.z;
    });
    for(int i=2;i<=N;i++){
        edges.push_back({arr[i-1].n,arr[i].n,arr[i].z-arr[i-1].z});
    }
    sort(edges.begin(),edges.end(),[](const tri &a, const tri &b)->bool{
        return a[2]<b[2];
    });
    
    ds A;
    ll ans=0;
    for(auto e:edges){
        if(A.find((int)e[0])==A.find((int)e[1]))continue;
        A.uni((int)e[0],(int)e[1]);
        ans+=e[2];
    }
    cout<<ans<<"\n";
    return 0;
}
