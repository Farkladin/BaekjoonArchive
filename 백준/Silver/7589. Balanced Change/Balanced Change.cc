#include "bits/stdc++.h"
using namespace std;
const string arr[5]={
    "$2","$1","50c","20c","10c"
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=0;
    while(1){
        tc++;
        int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        string s;cin>>s;
        if(a==0&&b==0&&c==0&&d==0&&e==0&&s=="$0.00")break;
        int t=(s[1]-'0')*100+(s[3]-'0')*10+s[4]-'0';
        pair<int,vector<int> >ans={1e9,{}};
        for(int i=a;i>=0;i--){
            int cur1=i*200;
            if(cur1>t)continue;
            for(int ii=b;ii>=0;ii--){
                int cur2=cur1+ii*100;
                if(cur2>t)continue;
                for(int iii=c;iii>=0;iii--){
                    int cur3=cur2+iii*50;
                    if(cur3>t)continue;
                    for(int iv=d;iv>=0;iv--){
                        int cur4=cur3+iv*20;
                        if(cur4>t)continue;
                        for(int v=e;v>=0;v--){
                            int cur5=cur4+v*10;
                            if(cur5!=t)continue;
                            int A=a-i,B=b-ii,C=c-iii,D=d-iv,E=e-v;
                            int mn=min({A,B,C,D,E}),tmp=(A-mn)*(A-mn)+(B-mn)*(B-mn)+(C-mn)*(C-mn)+(D-mn)*(D-mn)+(E-mn)*(E-mn);
                            if(ans.first>tmp){
                                ans.first=tmp;
                                ans.second={i,ii,iii,iv,v};
                            }
                        }
                    }
                }
            }
        }
        cout<<"Problem #"<<tc<<": ";
        if(ans.first==1e9){
            cout<<"not possible\n";
            continue;
        }
        vector<pair<int,string> >vp;
        for(int i=0;i<5;i++){
            if(ans.second[i]){
                vp.push_back({ans.second[i],arr[i]});
            }
        }
        for(int i=0;i<(int)vp.size();i++){
            if(i==0)cout<<vp[i].first<<" "<<vp[i].second;
            else if(i>0&&i<vp.size()-1)cout<<", "<<vp[i].first<<" "<<vp[i].second;
            else cout<<" and "<<vp[i].first<<" "<<vp[i].second;
        }
        cout<<" coin(s)\n";
    }
    return 0;
}
