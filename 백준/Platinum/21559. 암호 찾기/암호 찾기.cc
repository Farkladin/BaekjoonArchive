#include "bits/stdc++.h"
using namespace std;
using u64=u_int64_t;
const u64 p1=2147483647,p2=11410337850553,q1=101,q2=74747;
set<pair<u64,u64> >S;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    list<u64>L1,L2;
    int N,K;cin>>N>>K;
    string A;cin>>A;
    u64 hash1=0,hash2=0,k1=1,k2=1;
    for(int i=1;i<K;i++){
        k1=k1*q1%p1;
        k2=k2*q2%p2;
    }
    for(char &c:A){
        L1.push_back(u64(c-'0')*k1%p1);
        L2.push_back(u64(c-'0')*k2%p2);
        hash1=(hash1*q1%p1+u64(c-'0'))%p1;
        hash2=(hash2*q2%p2+u64(c-'0'))%p2;
        if(K==(int)L1.size()){
            S.insert({hash1,hash2});
            hash2=(hash2+p2-L2.front())%p2;
            hash1=(hash1+p1-L1.front())%p1;
            L1.pop_front();
            L2.pop_front();
        }
    }
    size_t sz=S.size();
    
    string B;cin>>B;
    L1.clear();L2.clear();
    hash1=hash2=0;
    
    for(char &c:B){
        L1.push_back(u64(c-'0')*k1%p1);
        L2.push_back(u64(c-'0')*k2%p2);
        hash1=(hash1*q1%p1+u64(c-'0'))%p1;
        hash2=(hash2*q2%p2+u64(c-'0'))%p2;
        if(K==(int)L1.size()){
            S.erase({hash1,hash2});
            hash2=(hash2+p2-L2.front())%p2;
            hash1=(hash1+p1-L1.front())%p1;
            L1.pop_front();
            L2.pop_front();
        }
    }
    
    cout<<sz-S.size()<<"\n";
    return 0;
}
