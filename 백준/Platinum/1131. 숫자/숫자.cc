#include "bits/stdc++.h"
using namespace std;

int po(int a, int b) {
    switch (b) {
        case 1: return a;
        case 2: return a*a;
        case 3: return a*a*a;
        case 4: return a*a*a*a;
        case 5: return a*a*a*a*a;
        case 6: return a*a*a*a*a*a;
        default: return -1;
    }
    
    return 0;
}

int dp[5000005], K;
int f(int x) {
    if(dp[x]) return dp[x];
    
    dp[x] = x;
    deque<int> dq({x});
    int y = x, k = -1;
    while (1) {
        int nxt = 0, t = y;
        do{
            nxt += po(t%10, K);
        }while(t/=10);
        
        if (dp[nxt]) {
            k = nxt;
            break;
        }
        
        y = nxt;
        dp[y] = y;
        dq.push_back(y);
    }
    
    stack<int> stk;
    while (!dq.empty() && dq.front() != k) {
        stk.push(dq.front());
        dq.pop_front();
    }
    
    int mn = dp[k];
    for (auto a:dq) {
        mn = min(a, mn);
    }
    
    for (auto a:dq) {
        dp[a] = mn;
    }
    
    while(!stk.empty()) {
        mn = min(stk.top(), mn);
        dp[stk.top()] = mn;
        stk.pop();
    }
    
    return dp[x];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int A, B; cin>>A>>B>>K;
    for (int i=1; i<=5; ++i) {
        (void)f(i);
    }
    
    int64_t sum = 0;
    for (int i=A; i<=B; ++i) {
        sum += f(i);
    }
    
    cout << sum << endl;
    
    return 0;
}
