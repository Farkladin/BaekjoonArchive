#include "bits/stdc++.h"
using namespace std;
struct Type {
    int x,y;
}arr[55];
int X[55], Y[55];
int64_t ans[55];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i].x>>arr[i].y;
        X[i]=arr[i].x;
        Y[i]=arr[i].y;
    }
    
    fill(ans,ans+N+1,1e9);
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            const int x=X[i], y=Y[j];
            sort(arr+1, arr+1+N, [&x, &y](const Type &a, const Type &b)->bool{
                return abs(x-a.x)+abs(y-a.y) < abs(x-b.x)+abs(y-b.y);
            });
            
            int64_t sum = 0;
            for(int k=1; k<=N; ++k){
                sum += abs(x-arr[k].x) + abs(y-arr[k].y);
                ans[k] = min(ans[k], sum);
            }
        }
    }
    
    for(int i=1; i<=N; ++i) cout<<ans[i]<<" ";
    cout<<"\n";
    
    return 0;
}
