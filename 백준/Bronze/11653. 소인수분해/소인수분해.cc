#include <iostream>
#include <cstdint>

using namespace std;

using ll = uint64_t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N; cin >> N;
    ll d = 2;
    
    while (N > 1) {
        while (N % d == 0) {
            cout << d << "\n";
            N /= d;
        }
        ++d;
    }
    
    return 0;
}
