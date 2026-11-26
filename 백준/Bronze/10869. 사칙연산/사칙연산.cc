#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A,B;cin>>A>>B;
    cout<<format("{:d}\n{:d}\n{:d}\n{:d}\n{:d}\n",A+B,A-B,A*B,A/B,A%B);
    return 0;
}
