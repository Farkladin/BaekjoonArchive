#include "bits/stdc++.h"
#pragma GCC optimize("Ofast") // Xcode build setting. It will ignored in local, but works in OJ.
// Gemini Optimized this code.

using namespace std;
using ll = int64_t;

template<ll p, ll R, ll N>
class NTT {
    ll modinvN;
    int rev[N];
    ll W[N], invW[N];

public:
    ll po(ll a, ll b) {
        ll ret = 1;
        while (b) {
            if (b & 1) ret = ret * a % p;
            a = a * a % p; b >>= 1;
        }
        return ret;
    }

    NTT() {
        modinvN = po(N, p - 2);
        
        // 1. Bit-reversal 배열 사전 계산 (O(N))
        for (int i = 1, j = 0; i < N; i++) {
            int bit = N >> 1;
            for (; j >= bit; bit >>= 1) j -= bit;
            j += bit;
            rev[i] = j;
        }
        
        // 2. 원시근(Roots of unity) 배열 사전 계산 (O(N))
        W[N / 2] = 1;
        invW[N / 2] = 1;
        ll w = po(R, (p - 1) / N);
        ll iw = po(w, p - 2);
        for (int i = N / 2 + 1; i < N; i++) {
            W[i] = W[i - 1] * w % p;
            invW[i] = invW[i - 1] * iw % p;
        }
        for (int i = N / 2 - 1; i > 0; i--) {
            W[i] = W[i << 1];
            invW[i] = invW[i << 1];
        }
    }

    void run(vector<ll>& a, const ll* roots) {
        for (int i = 1; i < N; i++) {
            if (i < rev[i]) swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < N; k *= 2) {
            for (int i = 0; i < N; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    // 루프 내부에서 동적 곱셈 연산(y * x % p) 제거됨
                    ll z = a[i + j + k] * roots[j + k] % p;
                    // 무거운 % 연산자를 조건부 덧셈/뺄셈으로 대체
                    a[i + j + k] = a[i + j] < z ? a[i + j] - z + p : a[i + j] - z;
                    a[i + j] = a[i + j] + z >= p ? a[i + j] + z - p : a[i + j] + z;
                }
            }
        }
    }

    void FFT(vector<ll>& a) { run(a, W); }
    void iFFT(vector<ll>& a) {
        run(a, invW);
        for (int i = 0; i < N; i++) a[i] = a[i] * modinvN % p;
    }
};

constexpr ll nttN = 65536;
constexpr ll p = 1092616193;
NTT<p, 3, nttN> X;

// const 레퍼런스로 받아 원본 보존. static 버퍼 활용으로 동적 할당 방지.
vector<ll> operator*(const vector<ll>& a, const vector<ll>& b) {
    static vector<ll> fa(nttN), fb(nttN);
    copy(a.begin(), a.end(), fa.begin());
    copy(b.begin(), b.end(), fb.begin());
    
    X.FFT(fa); 
    X.FFT(fb);
    
    vector<ll> ret(nttN);
    for (int i = 0; i < nttN; i++) {
        ret[i] = fa[i] * fb[i] % p;
    }
    
    X.iFFT(ret);
    return ret; // Return Value Optimization (RVO) 발동으로 복사 오버헤드 없음
}

// 할당을 최소화하고 한 번의 루프로 처리
vector<ll> operator-(const vector<ll>& ref) {
    vector<ll> ret(nttN);
    for (int i = 0; i < nttN; i++) {
        if (i & 1) ret[i] = ref[i] ? p - ref[i] : 0;
        else ret[i] = ref[i];
    }
    return ret;
}

vector<ll> BMsub(const vector<ll>& ref, const int isOdd = 0) {
    vector<ll> ret(nttN);
    int k = 0;
    for (int i = isOdd; i < nttN; i += 2) {
        ret[k++] = ref[i];
    }
    return ret;
}

ll BostanMori(ll N, vector<ll> P, vector<ll> Q) {
    vector<ll> mQ(nttN), U(nttN);
    while (N) {
        mQ = -Q;
        U = P * mQ;
        P = BMsub(U, N & 1);
        Q = BMsub(Q * mQ);
        N >>= 1;
    }
    return P[0] * X.po(Q[0], p - 2) % p;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int k; ll N; 
    cin >> k >> N;
    
    vector<ll> P(nttN, 0), Q(nttN, 0), tmp(nttN, 0);
    ll sum = 0;
    
    for (int i = k; i > 0; i--) {
        cin >> Q[i];
        sum = (sum + Q[i]) % p;
    }
    for (int i = k; i > 0; i--) {
        Q[i] = (p - Q[i] * X.po(sum, p - 2) % p) % p;
    }
    
    tmp[0] = 1; tmp[1] = p - 1; // -1 대신 p-1 사용 (언더플로우 방지)
    P[k] = 1;
    Q[0] = 1;
    Q = tmp * Q;
    
    ll ans = BostanMori(N, P, Q) % p;
    cout << ans << "\n";
    
    return 0;
}