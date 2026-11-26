#include <iostream>

int main() {
    int N; std::cin>>N;
    int r,g,b, x=0,y=0,z=0;
    while(N--) {
        std::cin>>r>>g>>b;
        r+=std::min(y,z);
        g+=std::min(x,z);
        b+=std::min(x,y);
        
        x=r; y=g; z=b;
    }
    std::cout<<std::min({x,y,z})<<"\n";
    
    return 0;
}
