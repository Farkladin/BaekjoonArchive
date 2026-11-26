#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;
int A[13], N;

inline void update(pii &a, const pii &b) {
    a.first = std::max(a.first, b.first);
    a.second = std::min(a.second, b.second);
}

pii sol(int i, int a, int b, int c, int d, int cur) {
    if (i > N) return pii{cur, cur};
    
    pii ret{-1e9, 1e9};
    
    if (a) {
        pii nxt = sol(i + 1, a - 1, b, c, d, cur + A[i]);
        update(ret, nxt);
    }
    
    if (b) {
        pii nxt = sol(i + 1, a, b - 1, c, d, cur - A[i]);
        update(ret, nxt);
    }
    
    if (c) {
        pii nxt = sol(i + 1, a, b, c - 1, d, cur * A[i]);
        update(ret, nxt);
    }
    
    if (d) {
        pii nxt = sol(i + 1, a, b, c, d - 1, cur / A[i]);
        update(ret, nxt);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i=1; i<=N; ++i) {
        cin >> A[i];
    }
    
    int a, b, c, d; cin >> a >> b >> c >> d;
    auto [mx, mn] = sol(2, a, b, c, d, A[1]);
    std::cout << mx << "\n" << mn <<"\n";
    
    return 0;
}
