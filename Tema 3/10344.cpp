#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[5];

bool backtracking(int idx, int acc) {
    if (idx == 5) {
        return acc == 23;
    }

    bool valid;
    if (idx == 0) {
        valid = backtracking(1, arr[0]);
    } else {
        valid = backtracking(idx+1, acc + arr[idx]);
        if (!valid) {
            valid = backtracking(idx+1, acc - arr[idx]);
            if (!valid) {
                valid = backtracking(idx+1, acc * arr[idx]);
            }
        }
    }

    return valid;
}

bool solve() {
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    if (arr[0] == 0)
        return false;
    else {
        // Code solve
        bool valid = false;
        sort(arr, arr + 5); // Tener los numeros ordenados para el next permutation
        do {
            valid = backtracking(0, 0);
            if (valid)
                break;
        } while (next_permutation(arr, arr + 5));
        
         backtracking(0, 0);
        if (valid) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
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