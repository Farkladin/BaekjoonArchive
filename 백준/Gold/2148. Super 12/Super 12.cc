#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
map<string,array<int,5> >mp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    {
        string tmp;cin>>tmp;
        while(tmp!="#"){
            mp[tmp]=array<int,5>();
            cin>>tmp;
        }
    }
    {
        int rn=0;
        string tmp;cin>>tmp;
        while(tmp!="#"){
            rn++;
            bool FLAG=true;
            for(int i=1;i*2<=(int)mp.size();i++){
                if(!FLAG){
                    cin>>tmp;
                }
                FLAG=false;
                string s;cin>>s;
                int a,b,c,d;cin>>a>>b>>c>>d;
                auto &A=mp[tmp],&B=mp[s];
                if(a>b){
                    A[0]+=4;
                    if(a-b<8)B[0]++;
                }else{
                    B[0]+=4;
                    if(b-a<8)A[0]++;
                }
                if(c>=4)A[0]++;
                if(d>=4)B[0]++;
                A[1]+=a;
                B[1]+=b;
                A[2]+=b;
                B[2]+=a;
                A[3]+=c;
                B[3]+=d;
                A[4]+=d;
                B[4]+=c;
            }
            vector<pair<array<int,3>,string> >arr;
            for(auto it:mp){
                arr.push_back({{-it.se[0],-it.se[1]+it.se[2],-it.se[3]},it.fi});
            }
            
            cout<<"Round "<<rn<<"\n";
            sort(arr.begin(),arr.end());
            for(auto &cur:arr){
                cout<<format("{:<20} {:>2}{:>4}{:>4}{:>3}{:>3}\n",cur.se,mp[cur.se][0],mp[cur.se][1],mp[cur.se][2],mp[cur.se][3],mp[cur.se][4]);
            }
            cout<<"\n";
            cin>>tmp;
        }
    }
    
    return 0;
}
