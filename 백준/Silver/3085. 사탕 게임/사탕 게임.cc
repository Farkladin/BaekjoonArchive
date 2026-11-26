#include "bits/stdc++.h"
using namespace std;

char arr[53][53];
int N;
int f(){
    int ans=0;
    for(int i=1;i<=N;i++){
        int cur=0;
        char c='!';
        for(int j=1;j<=N;j++){
            if(arr[i][j]!=c){
                ans=max(ans,cur);
                c=arr[i][j];
                cur=1;
            }else cur++;
        }
        ans=max(ans,cur);
        
        cur=0;
        c='!';
        for(int j=1;j<=N;j++){
            if(arr[j][i]!=c){
                ans=max(ans,cur);
                c=arr[j][i];
                cur=1;
            }else cur++;
        }
        ans=max(ans,cur);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<N;j++){
            swap(arr[i][j],arr[i][j+1]);
            ans=max(ans,f());
            swap(arr[i][j],arr[i][j+1]);
            if(i<N){
                swap(arr[i][j],arr[i+1][j]);
                ans=max(ans,f());
                swap(arr[i][j],arr[i+1][j]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
