#include "bits/stdc++.h"
using namespace std;

int A[500005];
int bs(const int &val,int le,int ri){
    int mid=(le+ri)>>1;
    if(A[mid]==val)return 1;
    else if(val<A[mid])return bs(val,le,mid-1)+1;
    else return bs(val,mid+1,ri)+1;
}

int ts(const int &val,int le,int ri){
    int lt=le+(ri-le)/3,rt=ri-(ri-le)/3;
    if(A[lt]==val)return 1;
    else if(A[rt]==val)return 2;
    else if(val<A[lt])return ts(val,le,lt-1)+2;
    else if(val<A[rt])return ts(val,lt+1,rt-1)+2;
    else return ts(val,rt+1,ri)+2;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=0;i<N;i++)A[i]=i;
    int ans1=0,ans2=0,ans3=0;
    for(int i=0;i<N;i++){
        int b=bs(i,0,N-1),t=ts(i,0,N-1);
        if(b<t)ans1++;
        else if(b==t)ans2++;
        else ans3++;
    }
    cout<<ans1<<"\n"<<ans2<<"\n"<<ans3<<"\n";
    return 0;
}
