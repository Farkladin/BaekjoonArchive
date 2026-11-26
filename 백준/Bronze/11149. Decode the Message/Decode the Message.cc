#include "bits/stdc++.h"
using namespace std;
using ll=long long;
char arr[27];
int mp[256];
int main(){
    for(int i='a';i<='z';i++){
        arr[i-'a']=i;
        mp[i]=i-'a';
    }
    arr[26]=' ';
    mp[' ']=1;
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;cin.ignore();
    while(T--){
        string line,s;
        getline(cin,line);
        stringstream ss(line);
        while(ss>>s){
            int sum=0;
            for(char c:s)sum+=mp[c];
            sum%=27;
            cout<<arr[sum];
        }
        cout<<"\n";
    }
    return 0;
}
