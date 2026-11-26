#include "bits/stdc++.h"
#include <format>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=0;
    while(1){
        int n;cin>>n;
        if(n==0)break;
        cout<<"Group "<<(++tc)<<"\n";
        vector<vector<string> >arr(n+3);
        for(int i=1;i<=n;i++){
            arr[i].resize(n+3);
            cin>>arr[i][0];
            for(int j=1;j<n;j++){
                cin>>arr[i][j];
            }
        }
        
        bool flag=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++){
                if(arr[i][j]=="N"){
                    cout<<format("{} was nasty about {}\n",arr[(i-j+n-1)%n+1][0],arr[i][0]);
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<"Nobody was nasty\n";
        }
        cout<<endl;
    }
    return 0;
}
