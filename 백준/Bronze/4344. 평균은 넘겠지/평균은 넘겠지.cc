#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C; cin>>C;
    cout<<fixed<<setprecision(3);
    while(C--){
        int N; cin>>N;
        float mu=0;
        vector<float>vec(N);
        for(auto &x:vec){
            cin>>x;
            mu+=x;
        }
        mu/=N;
        float cnt=0;
        for(auto &x:vec){
            if(x > mu) ++cnt;
        }
        cout<<cnt/N*100<<"%\n";
    }
    
    return 0;
}
