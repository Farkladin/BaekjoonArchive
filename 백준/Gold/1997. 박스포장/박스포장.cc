#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
bool E[100000003];
char box[203][103],arr[103][103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,w,b;cin>>n>>w>>b;
    memset(box,'.',sizeof(box));
    for(int i=1;i<=w;i++)box[b+b+1][i]='W';
    for(int i=1;i<=n;i++){
        memset(arr,'.',sizeof(arr));
        int h;cin>>h;
        for(int j=1;j<=b+b;j++){
            for(int k=1;k<=w;k++){
                if(box[j][k]=='X')box[j][k]='W';
            }
        }
        for(int j=1;j<=h;j++){
            for(int k=1;k<=w;k++){
                cin>>box[j][k];
                arr[j][k]=box[j][k];
            }
        }

        int fall=1e9;
        for(int j=b+1;j>0;j--){
            for(int k=1;k<=w;k++){
                if(box[j][k]=='X'){
                    for(int t=j+1;t<=b+b+1;t++){
                        if(box[t][k]=='W'){
                            fall=min(fall,t-j-1);
                        }
                    }
                }
            }
        }
        if(fall==1e9)fall=0;
        for(int j=b+1;j>0;j--){
            for(int k=1;k<=w;k++){
                if(box[j][k]=='X'){
                    swap(box[j+fall][k],box[j][k]);
                }
            }
        }
        
        bool newBox=false;
        for(int j=1;j<=b;j++){
            for(int k=1;k<=w;k++){
                if(box[j][k]=='X')newBox=true;
            }
        }
        
        if(newBox){
            int ch=0;
            for(int j=b+1;j<=b+b;j++){
                for(int k=1;k<=w;k++){
                    if(box[j][k]=='W')ch=max(ch,b+b-j+1);
                }
            }
            cout<<ch<<" ";
            memset(box,'.',sizeof(box));
            for(int j=b+b-h+1;j<=b+b;j++){
                for(int k=1;k<=w;k++){
                    box[j][k]=arr[j-b-b+h][k];
                }
            }
        }
    }
    int ch=0;
    for(int j=b+1;j<=b+b;j++){
        for(int k=1;k<=w;k++){
            if(box[j][k]=='X')ch=max(ch,b+b-j+1);
        }
    }
    cout<<ch<<"\n";
    return 0;
}
