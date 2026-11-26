#include "bits/stdc++.h"
using namespace std;

struct Data{
    int x,y,z;
}arr[55];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i].x;
        arr[i].y=i;
    }
    
    sort(arr+1,arr+1+N,[](const Data &a, const Data &b)->bool{
        return a.x<b.x||(a.x==b.x&&a.y<b.y);
    });
    
    for(int i=1;i<=N;i++){
        arr[i].z=i-1;
    }
    
    sort(arr+1,arr+1+N,[](const Data &a, const Data &b)->bool{
        return a.y<b.y;
    });
    
    for(int i=1;i<=N;i++){
        cout<<arr[i].z<<" ";
    }
    cout<<"\n";
    
    return 0;
}
