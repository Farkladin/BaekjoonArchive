#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int f(string s){
    if(s=="ng")return 11;
    switch(s[0]){
        case 'a':return 0;
        case 'b':return 1;
        case 'k':return 2;
        case 'd':return 3;
        case 'e':return 4;
        case 'g':return 5;
        case 'h':return 6;
        case 'i':return 7;
        case 'l':return 8;
        case 'm':return 9;
        case 'n':return 10;
        case 'o':return 12;
        case 'p':return 13;
        case 'r':return 14;
        case 's':return 15;
        case 't':return 16;
        case 'u':return 17;
        case 'w':return 18;
        case 'y':return 19;
    }
    return -1;
}

bool cmp(string a,string b){
    const int n=(int)min(a.size(),b.size());
    a.push_back('!');
    b.push_back('!');
    for(int i=0;i<n;i++){
        string ta(a.begin()+i,a.begin()+2+i),tb(b.begin()+i,b.begin()+2+i);
        int x=f(ta),y=f(tb);
        if(x<y)return true;
        else if(x>y)return false;
    }
    return a.size()<b.size();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<string>vs(N);
    for(int i=0;i<N;i++)cin>>vs[i];
    sort(vs.begin(),vs.end(),cmp);
    for(auto &s:vs)cout<<s<<"\n";
    return 0;
}
