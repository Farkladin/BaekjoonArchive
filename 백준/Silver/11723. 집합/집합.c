//
//  main.c
//  c-notepad
//
//  Created by Farkladin on 3/18/26.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>

char oper[10];

int main(void) {
    int M; scanf("%d", &M);
    
    uint64_t S = 0;
    int x;
    while (M--) {
        scanf("%6s %d\n", oper, &x);
        
        switch (oper[0]) {
            case 'a':
                if (oper[1] == 'd') {
                    S |= 1 << x;
                } else {
                    S = 0xFFFFFFFF;
                }
                break;
                
            case 'r':
                S &= ~(1 << x);
                break;
                    
            case 'c':
                printf("%d\n", (S & (1 << x)) != 0);
                break;
                    
            case 't':
                S ^= 1 << x;
                break;
                    
            case 'e':
                S = 0;
                break;
        }
    }
    
    return 0;
}
