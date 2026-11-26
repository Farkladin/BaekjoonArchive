#include "bits/stdc++.h"
using namespace std;

int main(){
    int T;cin>>T;
    cout<<fixed;
    cout.precision(10);
    for(int tc=1;tc<=T;tc++){
        int N;cin>>N;
        double sum=0;
        vector<double>arr(N+3);
        for(int i=1;i<=N;i++){
            cin>>arr[i];
        }
        for(int i=2;i<N;i++){
            arr[i]=min(arr[i],(arr[i-1]+arr[i+1])*0.5);
        }

        cout<<"Case #"<<tc<<": "<<arr[N-1]<<"\n";
    }
    return 0;
}
