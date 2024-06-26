#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int llaves, casas;
    cin >> llaves >> casas;
    long long total = (casas - llaves) * llaves;

    total += (llaves-1)* (llaves) / 2;

    cout << total << endl;

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