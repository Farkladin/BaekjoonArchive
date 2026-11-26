#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using tll = array<ll, 3>;

tll arr[100003];
vector<pair<ll,ll> > G[1003];
ll pos[1003], mx[1003], vis[1003];

ll find(ll x) {
    ll t = x;
    while (x != pos[x]) x = pos[x];
    while (t != pos[t]) {
        ll tmp = t;
        t = pos[t];
        pos[tmp] = x;
    }
    
    return x;
}

void join(ll x, ll y) {
    x = find(x);
    while (y != pos[y]) {
        ll tmp = y;
        y = pos[y];
        pos[tmp] = x;
    }
    
    pos[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll N, M; cin>>N>>M;
    for (ll i=1; i<=N; ++i) pos[i] = i;
    for (ll i=1; i<=M; ++i) {
        auto & [C,A,B] = arr[i];
        cin >> A >> B >> C;
    }
    
    sort(arr+1, arr+1+M);
    
    ll sum = 0;
    for (ll i=1; i<=M; ++i) {
        auto [w,u,v] = arr[i];
        if (find(u) != find(v)) {
            join(u,v);
            sum += w;
            G[u].emplace_back(v,w);
            G[v].emplace_back(u,w);
        }
    }
    
    ll Q; cin>>Q;
    for (ll i=1; i<=Q; ++i) {
        ll X, Y; cin>>X>>Y;
        memset(mx, 0, sizeof(mx));
        queue<ll> q; q.push(X); vis[X] = i;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto [v,w]:G[u]) {
                if (vis[v] == i) continue;
                vis[v] = i;
                mx[v] = max(mx[u], w);
                q.push(v);
            }
        }
        cout << sum - mx[Y] << "\n";
    }
    
    return 0;
}
