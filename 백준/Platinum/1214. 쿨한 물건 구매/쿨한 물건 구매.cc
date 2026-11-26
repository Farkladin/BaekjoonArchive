#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int D,P,Q;cin>>D>>P>>Q;
    if(P>Q)swap(P,Q);
    if(Q<=4){
        if(P==1){
            cout<<D<<"\n";
            return 0;
        }else if(P==2){
            if(D%2 == 1){
                if(Q%2 == 1 && Q<=D){
                    cout<<D<<"\n";
                    return 0;
                }else{
                    cout<<D+1<<"\n";
                    return 0;
                }
            }else{
                cout<<D<<"\n";
                return 0;
            }
        }else if(P==3){
            if(Q==3){
                cout<<(D+Q-1)/Q*Q<<"\n";
                return 0;
            }else if(D > 5){
                cout<<D<<"\n";
                return 0;
            }
        }else if(P==4){
            cout<<(D+Q-1)/Q*Q<<"\n";
            return 0;
        }
    }
    
    int ans=(D+Q-1)/Q*Q;
    const int N = min(P,(D+Q-1)/Q);
    for(int i=0;i<N;i++){
        int cur=i*Q+(D-i*Q+P-1)/P*P;
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
    return 0;
}
