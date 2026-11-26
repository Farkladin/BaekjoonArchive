#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <random>

using namespace std;

using ll = std::int64_t;

class planar {
public:
    ll x, y;
    planar(ll x=0, ll y=0): x(x), y(y) {}
    
    bool operator<(const planar &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

inline ll ccw(const planar &a,const planar &b,const planar &c){
    ll cp = (b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);
    return cp > 0 ? 1 : (cp < 0 ? -1 : 0);
}

planar arr[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, p; cin>>n>>p;
    for (int i=1; i<=n; ++i) {
        cin>>arr[i].x>>arr[i].y;
    }
    
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<ll> uid(1, n);
    
    int boundary = (n*p+99) / 100;
    for (int i=1; i<=1000; ++i) {
        ll u = uid(gen), v = uid(gen);
        if (u==v) v = v % n + 1;
        
        int cnt = 0;
        for (int j=1; j<=n; ++j) {
            if (!ccw(arr[u],arr[v],arr[j])) ++cnt;
        }
        
        if (cnt >= boundary) {
            cout << "possible" << endl;
            
            return 0;
        }
    }
    
    cout << "impossible" << endl;
    
    return 0;
}
