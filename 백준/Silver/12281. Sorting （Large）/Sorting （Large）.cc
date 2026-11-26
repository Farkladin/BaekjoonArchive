#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<": ";
        int N;cin>>N;
        vector<int>arr(N+2);
        priority_queue<int>odd,even;
        for(int i=1;i<=N;i++){
            int x;cin>>x;
            arr[i]=x&1;
            if(x&1)odd.push(-x);
            else even.push(x);
        }
        for(int i=1;i<=N;i++){
            if(arr[i]){
                cout<<-odd.top()<<" ";
                odd.pop();
            }else{
                cout<<even.top()<<" ";
                even.pop();
            }
        }
        cout<<"\n";
    }
    return 0;
}
