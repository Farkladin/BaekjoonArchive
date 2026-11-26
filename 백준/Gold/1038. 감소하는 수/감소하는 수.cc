#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    if(N<10){
        cout<<N<<"\n";
        return 0;
    }
    int cnt=-1;
    queue<ll>q;
    for(int i=0;i<10;i++)q.push(i);
    while(!q.empty()){
        ll u=q.front();q.pop();
        cnt++;
        if(cnt==N){
            cout<<u<<"\n";
            return 0;
        }
        for(int i=0;i<u%10;i++){
            ll x=u*10+i;
            if(x!=0){
                q.push(x);
            }
        }
    }
    cout<<"-1\n";
    return 0;
}
