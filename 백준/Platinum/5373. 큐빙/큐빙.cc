#include "bits/stdc++.h"
using namespace std;

const array<array<string,3>,6> initial{
    {
        {"www","www","www"},
        {"yyy","yyy","yyy"},
        {"rrr","rrr","rrr"},
        {"ooo","ooo","ooo"},
        {"ggg","ggg","ggg"},
        {"bbb","bbb","bbb"}
    }
};
array<array<string,3>,6> cub;

void U(){
    string tmp=cub[2][0];
    cub[2][0]=cub[5][0];
    cub[5][0]=cub[3][0];
    cub[3][0]=cub[4][0];
    cub[4][0]=tmp;
    
    array<string,3>&S=cub[0];
    tmp=S[0];
    for(int i=0;i<3;i++)S[0][2-i]=S[i][0];
    for(int i=0;i<3;i++)S[i][0]=S[2][i];
    for(int i=0;i<3;i++)S[2][i]=S[2-i][2];
    for(int i=0;i<3;i++)S[i][2]=tmp[i];
}

void D(){
    string tmp=cub[2][2];
    cub[2][2]=cub[4][2];
    cub[4][2]=cub[3][2];
    cub[3][2]=cub[5][2];
    cub[5][2]=tmp;
    
    array<string,3>&S=cub[1];
    tmp=S[0];
    for(int i=0;i<3;i++)S[0][2-i]=S[i][0];
    for(int i=0;i<3;i++)S[i][0]=S[2][i];
    for(int i=0;i<3;i++)S[2][i]=S[2-i][2];
    for(int i=0;i<3;i++)S[i][2]=tmp[i];
}

void F(){
    string tmp={cub[0][2][0],cub[0][2][1],cub[0][2][2]};
    for(int i=0;i<3;i++)cub[0][2][i]=cub[4][2-i][2];
    for(int i=0;i<3;i++)cub[4][i][2]=cub[1][0][i];
    for(int i=0;i<3;i++)cub[1][0][i]=cub[5][2-i][0];
    for(int i=0;i<3;i++)cub[5][i][0]=tmp[i];
    
    array<string,3>&S=cub[2];
    tmp=S[0];
    for(int i=0;i<3;i++)S[0][2-i]=S[i][0];
    for(int i=0;i<3;i++)S[i][0]=S[2][i];
    for(int i=0;i<3;i++)S[2][i]=S[2-i][2];
    for(int i=0;i<3;i++)S[i][2]=tmp[i];
}

void B(){
    string tmp={cub[0][0][0],cub[0][0][1],cub[0][0][2]};
    for(int i=0;i<3;i++)cub[0][0][i]=cub[5][i][2];
    for(int i=0;i<3;i++)cub[5][i][2]=cub[1][2][2-i];
    for(int i=0;i<3;i++)cub[1][2][i]=cub[4][i][0];
    for(int i=0;i<3;i++)cub[4][i][0]=tmp[2-i];
    
    array<string,3>&S=cub[3];
    tmp=S[0];
    for(int i=0;i<3;i++)S[0][2-i]=S[i][0];
    for(int i=0;i<3;i++)S[i][0]=S[2][i];
    for(int i=0;i<3;i++)S[2][i]=S[2-i][2];
    for(int i=0;i<3;i++)S[i][2]=tmp[i];
}

void L(){
    string tmp={cub[0][0][0],cub[0][1][0],cub[0][2][0]};
    for(int i=0;i<3;i++)cub[0][i][0]=cub[3][2-i][2];
    for(int i=0;i<3;i++)cub[3][2-i][2]=cub[1][i][0];
    for(int i=0;i<3;i++)cub[1][i][0]=cub[2][i][0];
    for(int i=0;i<3;i++)cub[2][i][0]=tmp[i];
    
    array<string,3>&S=cub[4];
    tmp=S[0];
    for(int i=0;i<3;i++)S[0][2-i]=S[i][0];
    for(int i=0;i<3;i++)S[i][0]=S[2][i];
    for(int i=0;i<3;i++)S[2][i]=S[2-i][2];
    for(int i=0;i<3;i++)S[i][2]=tmp[i];
}

void R(){
    string tmp={cub[0][0][2],cub[0][1][2],cub[0][2][2]};
    for(int i=0;i<3;i++)cub[0][i][2]=cub[2][i][2];
    for(int i=0;i<3;i++)cub[2][i][2]=cub[1][i][2];
    for(int i=0;i<3;i++)cub[1][i][2]=cub[3][2-i][0];
    for(int i=0;i<3;i++)cub[3][2-i][0]=tmp[i];
    
    array<string,3>&S=cub[5];
    tmp=S[0];
    for(int i=0;i<3;i++)S[0][2-i]=S[i][0];
    for(int i=0;i<3;i++)S[i][0]=S[2][i];
    for(int i=0;i<3;i++)S[2][i]=S[2-i][2];
    for(int i=0;i<3;i++)S[i][2]=tmp[i];
}

void sol(){
    cub=initial;
    
    int n;cin>>n;
    while(n--){
        char a,b;cin>>a>>b;
        switch(a){
            case 'U':
                U();
                if(b=='-'){U();U();}
                break;
            case 'D':
                D();
                if(b=='-'){D();D();}
                break;
            case 'F':
                F();
                if(b=='-'){F();F();}
                break;
            case 'B':
                B();
                if(b=='-'){B();B();}
                break;
            case 'L':
                L();
                if(b=='-'){L();L();}
                break;
            case 'R':
                R();
                if(b=='-'){R();R();}
                break;
            default:
                break;
        }
    }
    
    for(int i=0;i<3;i++){
        cout<<cub[0][i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        sol();
    }
    return 0;
}
