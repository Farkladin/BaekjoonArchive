#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;

pii arr[1'000'003];

inline int nextIdx(const int &idx, const int &N){
    return idx+1==N?0:idx+1;
}

inline int prevIdx(const int &idx, const int &N){
    return idx==0?N-1:idx-1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    int mn=1<<30,idx=0;
    for(int i=0; i<N; ++i){
        cin>>arr[i].first>>arr[i].second;
    }
    
    for(int i=0; i<N; ++i){
        const pii &cur=arr[i], &nxt=arr[nextIdx(i,N)];
        if(cur.first==nxt.first && ((cur.second>0 && nxt.second<0) || (cur.second<0 && nxt.second>0))){
            if(mn>cur.first){
                mn=cur.first;
                idx=i;
            }
        }
    }
    
    vector<pii>vert; vert.reserve(N);
    
    int x=-2e9;
    for(int i=0,it=idx; i<N; ++i,it=nextIdx(it,N)){
        const pii &cur=arr[it], &pre=arr[prevIdx(it,N)];
        if((cur.second>0 && pre.second<0) || (cur.second<0 && pre.second>0)){
            if(x>-2e9){
                if(x<cur.first){
                    vert.push_back(pii{x,0});
                    vert.push_back(pii{cur.first,1});
                }else{
                    vert.push_back(pii{cur.first,0});
                    vert.push_back(pii{x,1});
                }
                x=-2e9;
            }else{
                x=cur.first;
            }
        }
    }
    
    sort(vert.begin(),vert.end());
    
    stack<int>stk;
    pii ans{0,0};
    const size_t vert_size = vert.size();
    for(size_t i=0; i<vert_size; ++i){
        if(vert[i].second==0){
            if(stk.empty()) ++ans.first;
            stk.push(vert[i].first);
        }else{
            if(stk.top() == vert[i-1].first) ++ans.second;
            stk.pop();
        }
    }
    
    cout<<ans.first<<" "<<ans.second<<"\n";
    
    return 0;
}
