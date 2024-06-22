#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool solve() {
    int v, t;
    cin >> v;
    if (!cin) return false;

    // Code solve
    cin >> t;
    cout << 2*v*t << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}