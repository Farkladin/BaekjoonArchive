#include <iostream>
#include <functional>
#include <cstring>
#include <cstdlib>
#pragma GCC optimize("Os") // Xcode build setting. It will ignored in local, but works in OJ.

using namespace std;

int A[203], B[203], R[203], C[203];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    size_t N, K; cin >> N >> K;
    int cnt = 0;
    
    for (size_t i = 1; i <= 2 * N; ++i) {
        cin >> A[i];
        cnt += A[i] == 0;
    }
    
    const size_t n = N << 1;
    
    int ans = 0;
    auto next_i = [&n](const size_t &i)->size_t {
        return i == n ? 1 : i + 1;
    };
    
    while (1) {
        ++ans;
        for (size_t i = 1; i <= n; ++i) {
            int a = A[i];
            int b = R[i];
            B[next_i(i)] = a;
            C[next_i(i)] = b;
        }
        
        memcpy(A, B, sizeof(B));
        memcpy(R, C, sizeof(C));
        
        R[N] = 0;
        
        for (size_t i = N - 1; i > 0; --i) {
            if (A[i + 1] > 0 && !R[i + 1] && R[i]) {
                R[i + 1] = R[i];
                R[i] = 0;
                --A[i + 1];
                
                if (A[i + 1] == 0) {
                    ++cnt;
                }
            }
        }
        
        R[N] = 0;
        if (A[1] > 0) {
            --A[1];
            if(A[1] == 0) ++cnt;
            R[1] = 1;
        }
        
        if(cnt >= K) {
            cout << ans << "\n";
            
            return EXIT_SUCCESS;
        }
    }
    
    return EXIT_SUCCESS;
}
