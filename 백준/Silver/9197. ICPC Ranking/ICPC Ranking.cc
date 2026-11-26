#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        int M,T,P,R;cin>>M>>T>>P>>R;
        if(M==0&&T==0&&P==0&&R==0)break;
        vector<vector<int> >vv(T+1,vector<int>(3)),tmp(T+1,vector<int>(P+1));
        for(int i=1;i<=T;i++)vv[i][2]=i;
        while(R--){
            int m,t,p,j;cin>>m>>t>>p>>j;
            if(!j){
                vv[t][0]++;
                vv[t][1]-=m+tmp[t][p];
            }else{
                tmp[t][p]+=20;
            }
        }
        sort(vv.begin()+1,vv.begin()+1+T,greater<vector<int> >());
        vector<vector<int> >ans;
        vv[0][1]=2e9;
        for(int i=1;i<=T;i++){
            if(vv[i-1][1]!=vv[i][1]||vv[i-1][0]!=vv[i][0]){
                ans.push_back({vv[i][2]});
            }else{
                ans.back().push_back(vv[i][2]);
            }
        }
        bool flag=false;
        for(auto &v:ans){
            if(flag)cout<<",";
            flag=true;
            bool flag2=false;
            for(auto &x:v){
                if(flag2)cout<<"=";
                flag2=true;
                cout<<x;
            }
        }
        cout<<"\n";
    }
    return 0;
}
