#include "bits/stdc++.h"
using namespace std;

inline void inc(int &idx,const int &n){
    ++idx;
    if(idx>=n)idx=0;
}

inline void dec(int &idx,const int &n){
    --idx;
    if(idx<0)idx+=n;
}

void solve(){
    int sm,sc,si;cin>>sm>>sc>>si;
    string code;cin>>code;
    string input;cin>>input;
    vector<uint8_t>arr(sm),excuted1(sc),excuted2(sc),notloop(sc);
    vector<int>brck(sc);
    stack<int>stk;
    for(int iter=0;iter<sc;++iter){
        if(code[iter]=='[')stk.push(iter);
        else if(code[iter]==']'){
            int p=stk.top(); stk.pop();
            brck[iter]=p;
            brck[p]=iter;
        }
    }
    
    int it=0,i=0,j=0,cnt=0;
    while(++cnt <= 50'000'000){
        switch(code[i]){
            case '-':
                --arr[it];
                break;
            case '+':
                ++arr[it];
                break;
            case '<':
                dec(it,sm);
                break;
            case '>':
                inc(it,sm);
                break;
            case '[':
                if(arr[it]==0){
                    i=brck[i];
                }
                break;
            case ']':
                if(arr[it]!=0){
                    excuted1[i]=1;
                    i=brck[i];
                }
                break;
            case ',':
                if(j==si){
                    arr[it]=255;
                }else{
                    arr[it]=input[j++];
                }
                break;
            default:
                break;
        }
        
        i++;
        if(i==sc){
            cout<<"Terminates\n";
            return;
        }
    }
    
    cnt=0;
    while(++cnt <= 50'000'000){
        switch(code[i]){
            case '-':
                --arr[it];
                break;
            case '+':
                ++arr[it];
                break;
            case '<':
                dec(it,sm);
                break;
            case '>':
                inc(it,sm);
                break;
            case '[':
                if(arr[it]==0){
                    i=brck[i];
                }
                break;
            case ']':
                if(arr[it]!=0){
                    excuted2[i]=1;
                    i=brck[i];
                }else{
                    notloop[i]=1;
                }
                break;
            case ',':
                if(j==si){
                    arr[it]=255;
                }else{
                    arr[it]=input[j++];
                }
                break;
            default:
                break;
        }
        
        i++;
    }
    
    cout<<"Loops ";
    for(int iter=0;iter<sc;iter++){
        if(code[iter]==']' && excuted1[iter] && excuted2[iter] && !notloop[iter]){
            cout<<brck[iter]<<" "<<iter<<"\n";
            return;
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
