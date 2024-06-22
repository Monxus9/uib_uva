#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve() {
    unsigned long long tropas;
    cin >> tropas;
    if (tropas == 0) {
        cout << 0 << endl;
        return;
    }

    // Serie aritmetica despejar n
    // SUM = n (a1 + a1 + (n-1)*d) / 2
    // Para nuestro caso
    // SUM = n * (1 + n) / 2
    unsigned long long aux = 4*2*tropas - 1;
    unsigned long long filas = (sqrt(aux)-1)/2;
    unsigned long long total = (filas+1)*(2+filas)/2;
    if (tropas == total) {
        filas++;
    }
    cout << filas << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
  
    return 0;
}