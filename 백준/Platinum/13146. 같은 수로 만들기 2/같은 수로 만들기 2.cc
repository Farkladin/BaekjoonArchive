#include "bits/stdc++.h"

using namespace std;

using ll = long long;
ll arr[1000003];

constexpr ll BIG = static_cast<ll>(1e18);
int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    ll prev, mx;
    cin >> prev;
    mx = prev;
    
    ll first = prev;
    ll ans = 0;
    
    for (int i=2; i<=n; ++i) {
        ll cur; cin>>cur;
        mx = max(mx, cur);
        if (prev > cur) ans += prev - cur;
        prev = cur;
    }
    
    ans += mx - first;
    
    cout << ans << endl;
    
    return 0;
}
