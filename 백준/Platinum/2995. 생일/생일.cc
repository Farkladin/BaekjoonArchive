#include "bits/stdc++.h"
using namespace std;

struct Interval{
    int A,B;
    bool operator<(const Interval &rhs) const{
        return B>rhs.B || (B==rhs.B && A<rhs.A);
    }
    
}arr[100003];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i].A>>arr[i].B;
    }
    sort(arr+1,arr+1+N);
    
    vector<int>vi{arr[1].A}, anc(N+3), idx(N+3);
    idx[0]=1;
    anc[1]=-1;
    for(int i=2; i<=N; ++i){
        if(vi.back() <= arr[i].A){
            anc[i]=idx[vi.size()-1];
            idx[vi.size()]=i;
            vi.push_back(arr[i].A);
        }else{
            int pos = int(upper_bound(vi.begin(),vi.end(),arr[i].A)-vi.begin());
            vi[pos] = arr[i].A;
            idx[pos]=i;
            if(pos>0){
                anc[i]=idx[pos-1];
            }else{
                anc[i]=-1;
            }
        }
    }
    
    cout<<vi.size()<<"\n";
    
    stack<int>stk;
    int u=idx[vi.size()-1];
    while(u>=0){
        stk.push(u);
        u=anc[u];
    }
    while(!stk.empty()){
        int u=stk.top(); stk.pop();
        cout<<arr[u].A<<" "<<arr[u].B<<"\n";
    }
    cout<<"\n";
    
    return 0;
}
