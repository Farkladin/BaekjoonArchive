#include "bits/stdc++.h"
using namespace std;

int main(){
    string line;
    double x=0,v=0,d=0;
    cout<<fixed;
    cout.precision(2);
    while(getline(cin,line)){
        stringstream ss(line);
        string t;ss>>t;
        stringstream tt(t);
        string tmp,m=t;
        double y=0;
        getline(tt,tmp,':');
        y+=stod(tmp);
        getline(tt,tmp,':');
        y=y*60+stod(tmp);
        getline(tt,tmp);
        y=y*60+stod(tmp);
        d+=v*(y-x);
        if(ss>>t){
            v=stod(t);
        }else{
            cout<<m<<" "<<d/3600<<" km\n";
        }
        x=y;
    }

    return 0;
}
