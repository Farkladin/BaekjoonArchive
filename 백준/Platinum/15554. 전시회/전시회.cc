#include "bits/stdc++.h"

using namespace std;

using ll = long long;

struct Data {
    ll A,B;
} arr[500005];

inline bool cmp(const Data &a, const Data &b) {
    return a.A < b.A || (a.A == b.A && a.B < b.B);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll N; cin>>N;
    for (int i=1; i<=N; ++i) cin>>arr[i].A>>arr[i].B;
    
    sort(arr+1, arr+1+N, cmp);
    
    ll S = 0, ans = 0, D = 0;
    for (int i=1, j=1; i<=N; ++i) {
        D = max(arr[i].B, D + arr[i].B - (arr[i].A - arr[i-1].A));
        ans = max(ans, D);
    }
    
    cout << ans <<endl;
    
    return 0;
}
