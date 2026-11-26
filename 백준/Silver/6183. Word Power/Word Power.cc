#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int tp[1003][30];
string arr[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        for(char &c:arr[i]){
            if(c>'Z')c-='a';
            else c-='A';
        }
    }
    vector<string>brr;
    for(int i=1;i<=M;i++){
        string s;cin>>s;
        for(char &c:s){
            if(c>'Z')c-='a';
            else c-='A';
        }
        brr.push_back(s);
    }
    for(int i=1;i<=N;i++){
        int n=(int)arr[i].size();
        string &s=arr[i];
        for(int k=0;k<26;k++)tp[n][k]=-1;
        for(int j=n-1;j>=0;j--){
            for(int k=0;k<26;k++){
                tp[j][k]=tp[j+1][k];
            }
            tp[j][s[j]]=j;
        }
        int cnt=0;
        for(string &t:brr){
            int it=0;
            for(char &c:t){
                it=tp[it][c];
                if(it<0){
                    break;
                }
                it++;
            }
            if(it>0)cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
