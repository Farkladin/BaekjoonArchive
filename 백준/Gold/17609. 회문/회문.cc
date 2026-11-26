#include "bits/stdc++.h"
using namespace std;
int B[500003],T[500003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        string t(s.rbegin(),s.rend());
        if(s==t){
            cout<<"0\n";
            continue;
        }
        const int n=(int)s.size();
        s.push_back('@');
        t.push_back('@');
        int cnt1=0,cnt2=0;
        for(int i=0,j=0;i<n&&j<n;i++,j++){
            if(s[i]!=t[j]){
                if(s[i]==t[j+1]&&cnt1==0){
                    j++;
                    cnt1++;
                }else if(s[i+1]==t[j]&&cnt2==0){
                    i++;
                    cnt2++;
                }else{
                    goto tryAgain;
                }
            }
        }
        cout<<"1\n";
        continue;
        tryAgain:
        cnt1=cnt2=0;
        for(int i=0,j=0;i<n&&j<n;i++,j++){
            if(s[i]!=t[j]){
                if(s[i+1]==t[j]&&cnt1==0){
                    i++;
                    cnt1++;
                }else if(s[i]==t[j+1]&&cnt2==0){
                    j++;
                    cnt2++;
                }else{
                    cout<<"2\n";
                    goto nextCase;
                }
            }
        }
        cout<<"1\n";
        nextCase:
    }
    return 0;
}
