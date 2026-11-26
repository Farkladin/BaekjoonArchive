#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using str=string;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int tc=1;tc<=N;tc++){
        int T,NA,NB;cin>>T>>NA>>NB;
        vector<vector<int> >vv;
        for(int i=1;i<=NA;i++){
            string a,b;cin>>a>>b;
            int x=((a[0]-'0')*10+a[1]-'0')*60+((a[3]-'0')*10+a[4]-'0'),y=((b[0]-'0')*10+b[1]-'0')*60+((b[3]-'0')*10+b[4]-'0');
            vv.push_back({x,y,1});
        }
        for(int i=1;i<=NB;i++){
            string a,b;cin>>a>>b;
            int x=((a[0]-'0')*10+a[1]-'0')*60+((a[3]-'0')*10+a[4]-'0'),y=((b[0]-'0')*10+b[1]-'0')*60+((b[3]-'0')*10+b[4]-'0');
            vv.push_back({x,y,2});
        }
        sort(vv.begin(),vv.end());
        priority_queue<int>A,B;
        int ansA=0,ansB=0;
        for(auto &v:vv){
            if(v[2]==1){
                if(A.empty()||-A.top()>v[0]){
                    A.push(0);
                    ansA++;
                }
                A.pop();
                B.push(-v[1]-T);
            }else{
                if(B.empty()||-B.top()>v[0]){
                    B.push(0);
                    ansB++;
                }
                B.pop();
                A.push(-v[1]-T);
            }
        }
        cout<<format("Case #{:d}: {:d} {:d}\n",tc,ansA,ansB);
    }
    
    return 0;
}
