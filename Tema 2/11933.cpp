#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int num;

    while (scanf("%u", &num), num)
    {
        unsigned int a = 0, b = 0;
        unsigned int mask = 1;
        bool putA = true;
        while (mask <= num) {
            if (mask & num) {
                if (putA) {
                    a |= mask;
                } else {
                    b |=mask;
                }
                putA = !putA;
            }
            mask <<= 1;
        }
        printf("%d %d\n", a, b);
    }

  
    return 0;
}