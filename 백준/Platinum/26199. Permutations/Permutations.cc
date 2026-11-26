#include "bits/stdc++.h"
using namespace std;

const int sz = 1<<17;
int seg[(sz<<1)|3];
void add(int p,int dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1)seg[p]=seg[p*2]+seg[p*2+1];
}

int sfind(int x){
    int s=1,e=sz,pos=1;
    while(s<e){
        const int mid = (s+e)>>1;
        if(x>seg[pos*2]){
            x-=seg[pos*2];
            pos=pos*2+1;
            s=mid+1;
        }else{
            e=mid;
            pos=pos*2;
        }
    }
    return s;
}

int arr[100003], ans[100003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N;cin>>N;
    for(int i=1; i<=N; ++i){
        add(i,1);
        cin>>arr[i];
    }
    for(int i=1; i<=N; ++i){
        int p = sfind(1+arr[i]);
        ans[p]=i;
        add(p,-1);
    }
    
    vector<vector<int> >cycs;
    vector<int8_t>vis(N+3);
    
    for(int i=1; i<=N; ++i){
        if(vis[i])continue;
        int u=i;
        cycs.emplace_back();
        cout<<"(";
        while(!vis[u]){
            vis[u]=1;
            cycs.back().push_back(u);
            cout<<u;
            if(!vis[ans[u]])cout<<" ";
            u=ans[u];
        }
        cout<<") ";
    }
    
    cout<<"\n";
    
    return 0;
}
