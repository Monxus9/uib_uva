#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int num;
    if (!(cin >> num)) return false;
    else {
        // Code solve
        int diagonal = 1;
        int last_num = 1;

        while (last_num < num) {
            diagonal++;
            last_num+= diagonal;
        }

        if (diagonal % 2 == 0) {
            int idx = 1;
            while (last_num != num) {
                idx++;
                last_num--;
            }
            printf("TERM %d IS %d/%d\n", num, (diagonal-idx+1), idx);
        } else {
            int idx = 1;
            while (last_num != num) {
                idx++;
                last_num--;
            }
            printf("TERM %d IS %d/%d\n", num, idx, (diagonal-idx+1));
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}