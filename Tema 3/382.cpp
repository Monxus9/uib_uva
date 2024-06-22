#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int num;
    cin >> num;
    if (num == 0)
        return false;
    else {
        // Code solve
        int sum = 0;

        for (int i = 1; i < num; i++)
        {
            if (num % i == 0) {
                sum += i;
                if (sum > num) break;
            }
        }
        if (sum == num) {
            printf("%5d  PERFECT\n", num);
        } else if ( sum > num) {
            printf("%5d  ABUNDANT\n", num);
        } else {
            printf("%5d  DEFICIENT\n", num);
        }

    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    printf("PERFECTION OUTPUT\n");
    while(solve()) {
    }
    printf("END OF OUTPUT\n");
  
    return 0;
}