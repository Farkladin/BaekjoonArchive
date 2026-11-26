#include "bits/stdc++.h"
using namespace std;
int arr[1030][1030];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    while(N>>=1){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int x=i*2-1,y=j*2-1;
                vector<int>cur={arr[x][y],arr[x+1][y],arr[x][y+1],arr[x+1][y+1]};
                sort(cur.begin(),cur.end());
                arr[i][j]=cur[2];
            }
        }
    }
    cout<<arr[1][1]<<"\n";
    return 0;
}
