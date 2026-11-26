#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;
    getline(cin,s,':');
    int a=stoi(s);
    getline(cin,s,':');
    a=a*60+stoi(s);
    getline(cin,s);
    a=a*60+stoi(s);
    getline(cin,s,':');
    int b=stoi(s);
    getline(cin,s,':');
    b=b*60+stoi(s);
    getline(cin,s);
    b=b*60+stoi(s);
    int c=(b-a+24*60*60)%(24*60*60);
    if(c==0){
        cout<<"24:00:00\n";
        return 0;
    }
    string x=to_string(c/3600),y=to_string(c%3600/60),z=to_string(c%60);
    x=string(2-x.size(),'0')+x;
    y=string(2-y.size(),'0')+y;
    z=string(2-z.size(),'0')+z;
    cout<<x<<":"<<y<<":"<<z<<"\n";
    return 0;
}
