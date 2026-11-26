#include "bits/stdc++.h"
using namespace std;

int nxtx1[200006][30],nxty1[200006][30],nxtx2[200006][30],nxty2[200006][30];

void solve(){
    string X,Y,W; cin>>X>>Y>>W;
    
    const int n=(int)X.size(), m=(int)Y.size();
    
    memset(nxtx1,-1,4*(n+2)*30);
    memset(nxty1,-1,4*(m+2)*30);
    memset(nxtx2,-1,4*(n+2)*30);
    memset(nxty2,-1,4*(m+2)*30);
    
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<26; ++j){
            nxtx1[i][j] = nxtx1[i+1][j];
        }
        nxtx1[i][X[i]-'a']=i;
    }
    
    for(int i=m-1; i>=0; --i){
        for(int j=0; j<26; ++j){
            nxty1[i][j] = nxty1[i+1][j];
        }
        nxty1[i][Y[i]-'a']=i;
    }
    
    nxtx2[0][X[0]-'a']=0;
    for(int i=1; i<n; ++i){
        for(int j=0; j<26; ++j){
            nxtx2[i][j] = nxtx2[i-1][j];
        }
        nxtx2[i][X[i]-'a']=i;
    }
    
    nxty2[0][Y[0]-'a']=0;
    for(int i=1; i<m; ++i){
        for(int j=0; j<26; ++j){
            nxty2[i][j] = nxty2[i-1][j];
        }
        nxty2[i][Y[i]-'a']=i;
    }
    
    const int s = (int)W.size();
    vector<int>posx(s),posy(s);
    
    int it=-1, jt=-1;
    for(int i=0; i<s; ++i){
        it=nxtx1[it+1][W[i]-'a'];
        jt=nxty1[jt+1][W[i]-'a'];
        posx[i]=it;
        posy[i]=jt;
    }
    
    for(int i=0; i<26; ++i){
        int u=nxtx1[it+1][i],v=nxty1[jt+1][i];
        if(u!=-1 && v!=-1){
            cout<<"1\n";
            return;
        }
    }
    
    it=n; jt=m;
    for(int i=s-1; i>0; --i){
        int rx=nxtx2[it-1][W[i]-'a'], ry=nxty2[jt-1][W[i]-'a'], lx=posx[i-1], ly=posy[i-1];
        for(int j=0; j<26; ++j){
            int u=nxtx1[lx+1][j], v=nxty1[ly+1][j];
            if(lx<u&&u<rx && ly<v&&v<ry){
                cout<<"1\n";
                return;
            }
        }
        it=rx; jt=ry;
    }
    it=nxtx2[it-1][W[0]-'a'];
    jt=nxty2[jt-1][W[0]-'a'];
    
    if(it>0 && jt>0){
        for(int i=0; i<26; ++i){
            int u=nxtx2[it-1][i],v=nxty2[jt-1][i];
            if(u!=-1 && v!=-1){
                cout<<"1\n";
                return;
            }
        }
    }
    
    cout<<"0\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;cin>>T;
    while(T--)solve();
    
    return 0;
}
