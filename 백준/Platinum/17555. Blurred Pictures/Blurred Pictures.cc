#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    
    deque<pair<int,int> >maxDq,minDq;
    
    int ans=0;
    for(int i=1,j=1;i<=N;++i){
        int a,b;cin>>a>>b;
        
        while(!maxDq.empty() && maxDq.back().second<a)maxDq.pop_back();
        while(!minDq.empty() && minDq.back().second>b)minDq.pop_back();
        maxDq.push_back({i,a});
        minDq.push_back({i,b});
        
        while(1){
            int h=max((minDq.front().second-maxDq.front().second+1),0),w=i-j+1;
            if(w>h){
                if(maxDq.front().first==j)maxDq.pop_front();
                if(minDq.front().first==j)minDq.pop_front();
                ++j;
            }else{
                ans=max(ans,w);
                break;
            }
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
