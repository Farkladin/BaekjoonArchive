#include "bits/stdc++.h"

using namespace std;

int arr[55];
int f(int le,int ri) {
    if (gcd(le,ri) == 1) return 0;
    
    vector<int> L, R;
    for (int i=le+1; i<ri; ++i) {
        if (gcd(i,le) == 1) L.push_back(i);
        if (gcd(i,ri) == 1) R.push_back(i);
    }
    
    int ret = 1e9;
    for (auto x:L) {
        for (auto y:R) {
            if (x < y) ret = min(ret, (gcd(x,y)!=1) + 2);
            else if (x==y) return 1;
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for (int i=1; i<=N; ++i) cin>>arr[i];
    sort(arr+1,  arr+1+N);
    
    int ans = 0;
    for (int i=2; i<=N; ++i) {
        ans += f(arr[i-1], arr[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
