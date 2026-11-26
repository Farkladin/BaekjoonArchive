#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[13][13];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        vector<array<int,5> >va(14);
        for(int i=2;i<=10;i++){
            for(int j=0;j<5;j++)cin>>va[i][j];
        }
        va[1]={6,7,8,9,10};
        int mn=10,t=0;
        for(int i=0;i<=120;i++){
            vector<int>mt(13),used(13);
            vector<array<int,15> >tmp(13);
            memset(arr,0,sizeof(arr));
            for(int j=1;j<=5;j++){
                tmp[j][0]=1e9;
                for(int k=0;k<5;k++){
                    tmp[j][va[j][k]]=k;
                }
            }
            while(1){
                for(int k=6;k<=10;k++){
                    if(used[k])continue;
                    for(int j=0;j<5;j++){
                        int x=va[k][j],y=mt[x];
                        if(arr[x][k])continue;
                        if(tmp[x][k]<tmp[x][y]){
                            mt[x]=k;
                            used[k]=1;
                            used[y]=0;
                            arr[x][y]=1;
                            break;
                        }else{
                            arr[x][k]=1;
                        }
                    }
                }
                bool flag=true;
                for(int k=6;k<=10;k++)flag&=used[k]==1;
                if(flag)break;
            }
            mn=min(mn,mt[1]);
            if(i==0)t=mt[1];
            next_permutation(va[1].begin(),va[1].end());
        }
        cout<<(mn==t?"NO\n":"YES\n");
    }
    return 0;
}
