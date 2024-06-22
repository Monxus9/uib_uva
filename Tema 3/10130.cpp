#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int num;
vector<int> precio;
vector<int> peso;
vector<vector<int>> memo;

int best(int idx, int restante) {
    if (idx >= num) return 0;
    if (memo[idx][restante] != -1) return memo[idx][restante];

    int mejor;
    if (restante - peso[idx] >= 0) {
        mejor = max(
            best(idx+1, restante - peso[idx]) + precio[idx],
            best(idx+1, restante)
        );
    } else {
        mejor = best(idx+1, restante);
    }
    memo[idx][restante] = mejor;
    return mejor;
}

void solve() {
    
    cin >> num;

    precio.resize(num);
    peso.resize(num);
    memo.resize(num);

    // Memoria a -1
    for (size_t i = 0; i < num; i++)
    {
        vector<int> memo2(31);
        fill(memo2.begin(), memo2.end(), -1);
        memo[i] = memo2;
    }
    
    // Obtener precios
    for (size_t i = 0; i < num; i++)
    {
        cin >> precio[i];
        cin >> peso[i];
    }
    
    int total = 0;
    int pers;
    cin >> pers;

    for (size_t i = 0; i < pers; i++)
    {
        int max_peso;
        cin >> max_peso;
        total += best(0,max_peso);
    }
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