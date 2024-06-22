#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    int cols;
    cin >> cols;

    int array[cols] = {0};
    int num = 1;

    while (true) {
        int idx = 0;
        for (idx = 0; idx < cols; idx++)
        {
            if (array[idx] == 0) {
                array[idx] = num;
                break;
            } else {
                int aux = num + array[idx];
                int sqr = (int)sqrt(aux);
                if (sqr*sqr == aux) {
                    array[idx] = num;
                    break;
                }
            }
        }
        if (idx == cols) break;
        num++;
    }
    cout << (num-1) << endl;



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    while(casos--) {
        solve();
    }
  
    return 0;
}