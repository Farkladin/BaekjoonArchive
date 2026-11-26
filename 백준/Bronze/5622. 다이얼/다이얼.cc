#include <iostream>
using namespace std;
int arr[256];
constexpr int delta[10]={3,3,3,3,3,4,3,4};
int main(){
    int cnt=0,it=0,k=3;
    for(int i='A';i<='Z';i++){
        cnt++;
        arr[i]=k;
        if(cnt==delta[it]){
            it++;
            k++;
            cnt=0;
        }
    }
    string s;cin>>s;
    int ans=0;
    for(auto c:s){
        ans+=arr[c];
    }
    cout<<ans<<"\n";
    return 0;
}