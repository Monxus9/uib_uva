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
        int rango = sqrt(size);
        if (rango * rango != size) {
            rango++;
        }
        int rango1 = rango-1;
        int esquina_rango = 1+(rango1*rango1) + (rango* rango - (rango1 * rango1))/2;
        // cout << esquina_rango << endl;
        if (size == esquina_rango) {
            cout << rango << " " << rango << endl;
        } else if (size > esquina_rango) {
            if (rango % 2 == 0) {
                cout << rango << " " << (rango - (size - esquina_rango)) << endl;
            } else {
                cout << (rango - (size - esquina_rango)) << " " << rango << endl;
            }
        } else {
            if (rango % 2 != 0) {
                cout << rango << " " << (rango - (esquina_rango - size)) << endl;
            } else {
                cout << (rango - (esquina_rango - size)) << " " << rango << endl;
            }
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