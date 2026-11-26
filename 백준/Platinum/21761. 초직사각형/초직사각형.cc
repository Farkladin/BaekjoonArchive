#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pic = pair<ll,char>;
priority_queue<ll>card[4];
ll arr[4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,K; cin>>N>>K;
    priority_queue<pic>cur;
    int A0,B0,C0,D0; cin>>A0>>B0>>C0>>D0;
    cur.push(pic{-A0,'A'});
    cur.push(pic{-B0,'B'});
    cur.push(pic{-C0,'C'});
    cur.push(pic{-D0,'D'});
    arr[0]=A0;
    arr[1]=B0;
    arr[2]=C0;
    arr[3]=D0;
    
    for(int i=1; i<=N; ++i){
        char c; ll a; cin>>c>>a;
        card[c-'A'].push(a);
    }
    
    while(K--){
        double mx=0;
        int idx=-1;
        double cube[4] = {(double)arr[1]*arr[2]*arr[3], (double)arr[0]*arr[2]*arr[3], (double)arr[0]*arr[1]*arr[3], (double)arr[0]*arr[1]*arr[2]};
        for(int i=0; i<4; ++i){
            if(!card[i].empty()){
                if(mx<cube[i]*card[i].top()){
                    mx=cube[i]*card[i].top();
                    idx=i;
                }
            }
        }
        cout<<char(idx+'A')<<" "<<card[idx].top()<<"\n";
        arr[idx]+=card[idx].top();
        card[idx].pop();
    }
    
    return 0;
}
