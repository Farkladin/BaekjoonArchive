#include "bits/stdc++.h"
using namespace std;

int dp[2003][2003], arr[2003];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for (int i=1; i<=N; ++i) {
        cin>>arr[i];
    }

    for (int l = N-1; l>=1; --l) {
        for (int r=l+1; r<=N; r++) {
            if (arr[l] == arr[r]) {
                dp[l][r] = dp[l+1][r-1] +1;
                continue;
            }
            
            int cur = max(dp[l+1][r], dp[l][r-1]);
            
            for (int m = l+1; m<r; m++) {
                cur = max(cur, dp[l][m] + dp[m+1][r]);
            }
            
            dp[l][r] = cur;
        }
    }
    
    cout << dp[1][N] << endl;
    
    return 0;
}
