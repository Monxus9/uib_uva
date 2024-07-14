#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,k;

class Cola {
    public:
        deque<pair<long long, int>> cola;
        int added, removed;
        Cola() {
            added = 0;
            removed = 0;
        }

        long long min() {
            return cola.front().first;
        }

        void insert(long long elem) {
            while (!cola.empty() && cola.back().first >= elem) {
                cola.pop_back();
            }
            cola.push_back({elem, added});
            added++;
        }

        void remove() {
            if (!cola.empty() && cola.front().second == removed) {
                cola.pop_front();
            }
            removed++;
        }
};


void solve() {
    cin >> n >> k;
    Cola micola = Cola();

    micola.insert(0);

    long long puntos;
    long long total = 0;

    // Funcion "pierde"
    for (int i = 1; i <= n; i++)
    {
        cin >> puntos;
        total += puntos;
        if (i <= k) {
            micola.insert(puntos);
            //cout << i << ": " << puntos << endl;
        } else {
            long long min_ventana = micola.min();
            micola.remove();
            micola.insert(puntos + min_ventana);
           //cout << i << ": " << puntos + min_ventana << endl;
        }

    }

    // Una ultima partida
    total -= micola.min();

    cout << total << endl;
    // cout << endl;

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