#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int R,C,A,B;cin>>R>>C>>A>>B;
    for(int i=1;i<=R;i++){
        for(int a=1;a<=A;a++){
            for(int j=1;j<=C;j++){
                char c=((i+j)&1)==0?'X':'.';
                for(int b=1;b<=B;b++)cout<<c;
            }
            cout<<"\n";
        }
    }
    return 0;
}
