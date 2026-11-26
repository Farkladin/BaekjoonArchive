#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr string_view A="QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./`1234567890-=";
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;
    while(getline(cin,s)){
        for(char c:s){
            if(c==' '){
                cout<<" ";
                continue;
            }
            for(int i=0;i<(int)A.size();i++){
                if(A[i]==c){
                    cout<<A[i-1];
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
