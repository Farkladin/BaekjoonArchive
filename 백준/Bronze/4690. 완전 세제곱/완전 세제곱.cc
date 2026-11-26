#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int a=1;a<=100;a++){
        for(int b=2;b<=100;b++){
            for(int c=b+1;c<=100;c++){
                for(int d=c+1;d<=100;d++){
                    if(a*a*a==b*b*b+c*c*c+d*d*d){
                        cout<<format("Cube = {:d}, Triple = ({:d},{:d},{:d})\n",a,b,c,d);
                    }
                }
            }
        }
    }
    return 0;
}
