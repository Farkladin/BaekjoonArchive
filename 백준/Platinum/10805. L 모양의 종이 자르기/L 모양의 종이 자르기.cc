#include "bits/stdc++.h"
using namespace std;

int dp[55][55][55][55];

int f(int h1, int w1, int h2, int w2) {
    int &ret = dp[h1][w1][h2][w2];
    if (h1 == w1 && h2 == 0 && w2 == 0) return 0;
    if (ret) return ret;
    ret = 1e9;
    for (int x=1; x<w1; ++x) {
        if (x < w1-w2) {
            ret = min(ret, f(h1,x,0,0) + f(h1,w1-x,h2,w2) + 1);
        } else if (x > w1-w2){
            ret = min(ret, f(h1,x,h2,x-(w1-w2)) + f(h1-h2, w1-x, 0, 0) + 1);
        } else {
            ret = min(ret, f(h1,x,0,0) + f(h1-h2, w1-x, 0, 0) + 1);
        }
    }
    
    for (int y=1; y<h1; ++y) {
        if (y < h1-h2) {
            ret = min(ret, f(y,w1,0,0) + f(h1-y,w1,h2,w2) + 1);
        } else if (y > h1-h2){
            ret = min(ret, f(y,w1,y-(h1-h2),w2) + f(h1-y, w1-w2, 0, 0) + 1);
        } else {
            ret = min(ret, f(y,w1,0,0) + f(h1-y,w1-w2,0,0) + 1);
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int h1,w1,h2,w2;cin>>h1>>w1>>h2>>w2;
    cout << f(h1, w1, h2, w2) + 1<<endl;
    
    return 0;
}
