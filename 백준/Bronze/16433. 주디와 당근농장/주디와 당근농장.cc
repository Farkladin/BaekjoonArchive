#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,R,C;cin>>N>>R>>C;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<((i+j)%2==(R+C)%2?'v':'.');
        }
        cout<<"\n";
    }
    return 0;
}
