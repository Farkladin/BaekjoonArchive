#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;
char arr[1003], brr[1003];
int pos[1003][4], dp[1003][1003];
pii anc[1003][1003];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    
    int M; cin>>M;
    for(int j=1; j<=M; ++j) cin>>brr[j];
    
    int ans=0;
    pii idx{0,0};
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(arr[i]==brr[j] && dp[i][j] < dp[i-1][j-1]+3){
                dp[i][j] = dp[i-1][j-1]+3;
                anc[i][j]=pii{i-1,j-1};
            }
            
            if(dp[i][j] < dp[i-1][j-1]-2){
                dp[i][j] = dp[i-1][j-1]-2;
                anc[i][j] = pii{i-1,j-1};
            }
            
            if(dp[i][j] < dp[i-1][j]-2){
                dp[i][j] = dp[i-1][j]-2;
                anc[i][j]=pii{i-1,j};
            }
            
            if(dp[i][j] < dp[i][j-1]-2){
                dp[i][j] = dp[i][j-1]-2;
                anc[i][j]=pii{i,j-1};
            }
            
            if(dp[i][j] > ans){
                ans=dp[i][j];
                idx.first = i;
                idx.second = j;
            }
        }
    }
    
    cout<<ans<<"\n";
    pii tmp = idx;
    string A,B;
    while(dp[tmp.first][tmp.second]>0){
        pii prev = anc[tmp.first][tmp.second];
        if(prev.first==tmp.first-1)A.push_back(arr[tmp.first]);
        if(prev.second==tmp.second-1)B.push_back(brr[tmp.second]);
        tmp=prev;
    }
    
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    cout<<A<<"\n"<<B<<"\n";
    
    return 0;
}
