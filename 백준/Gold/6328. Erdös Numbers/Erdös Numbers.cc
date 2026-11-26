#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=0;
    while(1){
        tc++;
        int idx=0;
        int p,n;cin>>p>>n;
        if(p==0&&n==0)break;
        map<string,int>mp;
        vector<vector<int> >G(10003);
        cin.ignore();
        while(p--){
            string s,tmp;
            getline(cin,s);
            bool flag=false;
            vector<int>arr;
            for(auto c:s){
                if(c==','){
                    if(flag){
                        if(tmp=="Erdos, P."){
                            if(!mp[tmp])mp[tmp]=10001;
                            arr.push_back(10001);
                        }else{
                            if(!mp[tmp])mp[tmp]=++idx;
                            arr.push_back(mp[tmp]);
                        }
                        tmp.clear();
                    }
                    flag^=1;
                }
                
                if(c==':'){
                    if(tmp=="Erdos, P."){
                        if(!mp[tmp])mp[tmp]=10001;
                        arr.push_back(10001);
                    }else{
                        if(!mp[tmp])mp[tmp]=++idx;
                        arr.push_back(mp[tmp]);
                    }
                    tmp.clear();
                    break;
                }
                
                tmp.push_back(c);
                if(tmp==" "||tmp==",")tmp.clear();
            }
            
            for(int a:arr){
                for(int b:arr){
                    if(a!=b)G[a].push_back(b);
                }
            }
        }
        
        queue<int>q;q.push(10001);
        vector<int>dist(10003,-1);dist[10001]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:G[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        
        cout<<format("Database #{:d}\n",tc);
        while(n--){
            string s;
            getline(cin,s);
            cout<<s<<": ";
            if(dist[mp[s]]==-1)cout<<"infinity\n";
            else cout<<dist[mp[s]]<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
