#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string s;
        getline(cin,s,',');
        int ans=stoi(s);
        getline(cin,s);
        cout<<stoi(s)+ans<<"\n";
    }
    return 0;
}
