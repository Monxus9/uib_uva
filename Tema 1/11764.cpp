#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int num_c;

void solve() {
    int saltos, altura_actual, altura_anterior;
    cin >> saltos;
    int up = 0;
    int down = 0;

    cin >> altura_anterior;
    saltos--;
    while (saltos--) {
        cin >> altura_actual;
        if (altura_actual < altura_anterior) {
            down++;
        } else if (altura_actual > altura_anterior) {
            up++;
        }
        altura_anterior = altura_actual;
        
    }

    cout << "Case " << num_c++ << ": " << up << " " << down << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    num_c = 1;

    while(casos--) {
        solve();
    }
  
    return 0;
}