#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
vector<string>vs;
bool used[503];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vs.resize(N);
    vector<string>tmp;
    for(int i=0;i<N;i++){
        cin>>vs[i];
    }
    for(auto &s:vs){
        cout<<"? "<<s<<endl;
        int x;cin>>x;
        if(x){
            tmp.push_back(s);
        }
    }
    if(tmp.size()==1){
        cout<<"! "<<tmp.front()<<endl;
    }else if(tmp.size()==2){
        for(auto &s:tmp){
            cout<<"? "<<s<<endl;
            int x;cin>>x;
            if(x){
                cout<<"! "<<s<<endl;
                break;
            }
        }
    }else{
        for(auto &s:vs){
            cout<<"? "<<s<<endl;
            int x;cin>>x;
            if(x){
                cout<<"! "<<s<<endl;
                break;
            }
        }
    }
    return 0;
}
