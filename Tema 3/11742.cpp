#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
        return false;
    else {
        // Code solve
        int arr[n];
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = i;
        }

        int cond[m][3];
        for (size_t i = 0; i < m; i++)
        {
            cin >> cond[i][0];
            cin >> cond[i][1];
            cin >> cond[i][2];
        }

        int sols = 0;
        int posA, posB, dist;
        do {
            bool valid = true;
            for (size_t i = 0; i < m && valid; i++)
            {
                posA = 0, posB = 0;
                for (posA = 0; posA < n; posA++)
                {
                    if (arr[posA] == cond[i][0]) {
                        break;
                    }
                }
                for (posB = 0; posB < n; posB++)
                {
                    if (arr[posB] == cond[i][1]) {
                        break;
                    }
                }
                dist = abs(posB - posA);
                if (cond[i][2] < 0) {
                    valid = dist >= -cond[i][2];
                } else {
                    valid = dist <= cond[i][2];
                }
                
            }
            

            if (valid) sols++;

        } while (next_permutation(arr, arr+n));
        
        cout << sols << endl;
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