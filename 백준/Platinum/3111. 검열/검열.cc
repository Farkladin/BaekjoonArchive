#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string A,T;cin>>A>>T;
    const int n=(int)T.size(),m=(int)A.size();;
    string L(n,'@'),R(n,'@'),rA(A.rbegin(),A.rend());
    int lt=0,rt=0;
    deque<char>dq(T.begin(),T.end());
    while(!dq.empty()||lt>0||rt>0){
        bool fail=true;
        while(!dq.empty()||rt>0){
            if(dq.empty()){
                dq.push_back(R[--rt]);
            }
            L[lt++]=dq.front();dq.pop_front();
            if(lt>=m){
                if(string(L.begin()+lt-m,L.begin()+lt)==A){
                    fail=false;
                    lt-=m;
                    break;
                }
            }
        }
        if(fail)break;
        fail=true;
        while(!dq.empty()||lt>0){
            if(dq.empty()){
                dq.push_back(L[--lt]);
            }
            R[rt++]=dq.back();dq.pop_back();
            if(rt>=m){
                if(string(R.begin()+rt-m,R.begin()+rt)==rA){
                    fail=false;
                    rt-=m;
                    break;
                }
            }
        }
        if(fail)break;
    }
    for(int i=0;i<lt;i++)cout<<L[i];
    for(int i=rt-1;i>=0;i--)cout<<R[i];
    cout<<"\n";
    return 0;
}
