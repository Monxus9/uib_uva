#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int size;
    cin >> size;
    if (size == 0)
        return false;
    else {
        int max_wining = 0;
        int actual = 0;

        for (size_t i = 0; i < size; i++)
        {
            int num;
            cin >> num;
            actual += num;
            if (actual < 0) {
                actual = 0;
            }
            if (actual > max_wining) {
                max_wining = actual;
            }
        }
        
        if (max_wining == 0) {
            printf("Losing streak.\n");
        } else {
            printf("The maximum winning streak is %d.\n", max_wining);
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