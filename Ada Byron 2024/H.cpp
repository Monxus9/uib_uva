#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long long> cabezas_nivel;
int multiplicador;
long long modulo = 1000000007;

void leer_cabezas(int nivel) {
    int cabezas;
    cin >> cabezas;
    if (cabezas == 0) return;

    if (nivel == cabezas_nivel.size()) {
        cabezas_nivel.push_back(cabezas);
    } else {
        cabezas_nivel[nivel] += cabezas;
    }

    while (cabezas > 0) {
        leer_cabezas(nivel+1);
        cabezas--;
    }

}


bool solve() {
    
    cin >> multiplicador;
    if (multiplicador == 0) return false;

    cabezas_nivel.clear();

    leer_cabezas(0);

    long long total = 0;
    for (int i = cabezas_nivel.size()-1; i >= 0; i--)
    {
        // cout << cabezas_nivel[i] << endl;

        total += cabezas_nivel[i];
        total %= modulo;
        if (i == 0) continue;
        long long acumula = (cabezas_nivel[i] * multiplicador) % modulo;
        cabezas_nivel[i-1] += acumula;
    }

    cout << total << endl;
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}