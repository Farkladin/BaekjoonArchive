#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<": ";
        int query;cin>>query;
        if(query==1){
            ull n;cin>>n;
            ull t=n;
            ull p=1,q=1;
            stack<bool>stk;
            while(t>1){
                stk.push((t&1)==1);
                t>>=1;
            }
            while(!stk.empty()){
                if(stk.top()){
                    p=p+q;
                }else{
                    q=p+q;
                }
                stk.pop();
            }
            cout<<p<<" "<<q<<"\n";
        }else{
            ull p,q;cin>>p>>q;
            
            stack<ull>stk;
            while(p!=q){
                if(p>q){
                    stk.push(1);
                    p-=q;
                }else{
                    stk.push(0);
                    q-=p;
                }
            }
            
            ull n=1;
            while(!stk.empty()){
                n=(n<<1)|stk.top();stk.pop();
            }
            cout<<n<<"\n";
        }
    }
    return 0;
}
