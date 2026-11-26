#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
char arr[53][53];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;cin>>c;
            if(arr[i][j]=='.'||!arr[i][j])arr[i][j]=c;
            if(arr[i][j]!='.'){
                arr[i][M-j-1]=arr[i][j];
            }
        }
        arr[i][M]='\0';
        cout<<arr[i]<<"\n";
    }
    return 0;
}
