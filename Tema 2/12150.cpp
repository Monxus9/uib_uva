#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    int size;
    cin >> size;
    if (size == 0)
        return false;
    else {
        // Code solve
        int pos[size] = {0};
        bool valid = true;
        int num, index;
        for (size_t i = 0; i < size; i++)
        {
            cin >> num;
            cin >> index;
            
            if (valid) {
                index += i;
                if (index >= 0 && index < size && pos[index] == 0) {
                    pos[index] = num;
                } else {
                    valid = false;
                }
                // cout << num << endl;
            }

        }

        if (valid) {
            for (size_t i = 0; i < size; i++)
            {
                cout << pos[i];
                if (i != size - 1) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
            
        } else {
            cout << -1 << endl;
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