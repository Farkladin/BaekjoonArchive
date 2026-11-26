#include <iostream>
#include <string>

using namespace std;


string operator*(const string rhs, int lhs) {
    string ret = "";
    while (lhs--) ret += rhs;
    
    return ret;
}

using str = string;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N; cin >> N;
    
    for(int i=1; i<=N; ++i){
        cout << str(" ") * (N-i) << str("*") * (i * 2 - 1) << "\n";
    }
    
    for(int i=N-1; i>0; --i){
        cout << str(" ") * (N-i) << str("*") * (i * 2 - 1) << "\n";
    }
    
    return 0;
}
