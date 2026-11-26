#include "bits/stdc++.h"
using namespace std;

const int sz = 1<<17;
vector<int> tree[(sz<<1)|3];

int mtCnt(int S,int E,int s,int e,int pos,int k){
    if(S>e || s>E) return 0;
    if(S<=s && e<=E){
        auto p = upper_bound(tree[pos].begin(),tree[pos].end(),k);
        if(p==tree[pos].end()) return 0;
        return e-s+1-int(p-tree[pos].begin());
    }
    
    const int mid = (s+e)>>1;
    return mtCnt(S,E,s,mid,pos*2,k) + mtCnt(S,E,mid+1,e,pos*2+1,k);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=sz; i<sz+N; ++i){
        int x; cin>>x;
        tree[i]={x};
    }
    
    for(int i=sz-1; i>0; --i){
        int l=i*2, r=i*2+1;
        tree[i].resize(tree[l].size()+tree[r].size());
        auto lt = tree[l].begin(), rt = tree[r].begin();
        for(auto &x:tree[i]){
            if(lt==tree[l].end()){
                x = *rt;
                ++rt;
            }else if(rt==tree[r].end()){
                x = *lt;
                ++lt;
            }else if(*lt < *rt){
                x = *lt;
                ++lt;
            }else{
                x = *rt;
                ++rt;
            }
        }
    }
    
    int M; cin>>M;
    while(M--){
        int i,j,k; cin>>i>>j>>k;
        cout<<mtCnt(i,j,1,sz,1,k)<<"\n";
    }
    
    return 0;
}
