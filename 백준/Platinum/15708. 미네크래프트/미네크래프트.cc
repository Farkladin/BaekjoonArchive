#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N, T, P; cin>>N>>T>>P;T+=P;
    
    priority_queue<int> pq;
    int ans = 0, sum = 0;
    for (int i=1; i<=N; ++i) {
        int x; cin>>x;
        T = max(T-P,0);
        while (!pq.empty() && sum > T) {
            sum -= pq.top();
            pq.pop();
        }
        
        if (sum + x <= T) {
            sum += x;
            pq.push(x);
        } else if (!pq.empty() && pq.top() > x) {
            pq.push(x);
            sum += x - pq.top();
            pq.pop();
        }
        
        ans = max(ans, (int)pq.size());
    }
    
    cout << ans <<endl;
    
    return 0;
}
