#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        int n;string s;cin>>n>>s;
        if(n==0)break;
        cout<<s<<"\n";
        vector<std::array<string,3> >arr(n);
        for(auto &[a,b,c]:arr){
            cin>>a>>c>>b;
            b=string(20-b.size(),'0')+b;
        }
        bool flag=false;
        for(auto &[a,b,c]:arr){
            flag=false;
            cout<<a<<": ";
            for(auto &[A,B,C]:arr){
                if(c==C)continue;
                if(c=="buy"&&b>=B){
                    cout<<A<<" ";
                    flag=true;
                }else if(c=="sell"&&b<=B){
                    cout<<A<<" ";
                    flag=true;
                }
            }
            if(!flag)cout<<"NO-ONE";
            cout<<"\n";
        }
    }
    return 0;
}
