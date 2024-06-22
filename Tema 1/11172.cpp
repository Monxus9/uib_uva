#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    int n1, n2;
    cin >> n1;
    cin >> n2;

    if (n1 > n2) {
        cout << '>' << endl;
    }
    if (n1 < n2) {
        cout << '<' << endl;
    }
    if (n1 == n2) {
        cout << '=' << endl;
    }

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
