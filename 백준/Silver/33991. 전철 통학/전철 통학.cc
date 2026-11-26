#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
char arr[103][103];
int dist(int x,int y,int X,int Y){
    return abs(x-X)+abs(y-Y);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int X1,Y1,X2,Y2,X3,Y3;cin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
    int Q;cin>>Q;
    while(Q--){
        int X,Y,T1,T2,T3;cin>>X>>Y>>T1>>T2>>T3;
        cout<<min({max((dist(X1,Y1,X,Y)+T1-1)/T1*T1,dist(X1,Y1,X,Y)),max((dist(X2,Y2,X,Y)+T2-1)/T2*T2,dist(X2,Y2,X,Y)),max((dist(X3,Y3,X,Y)+T3-1)/T3*T3,dist(X3,Y3,X,Y))})<<"\n";
    }
    return 0;
}
