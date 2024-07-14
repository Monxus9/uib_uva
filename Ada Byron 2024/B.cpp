#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int filas, cambios;
    cin >> filas >> cambios;
    if (filas == 0 && cambios == 0) return false;

    int asientos[filas * 6] = {0};

    for (int i = 1; i <= filas * 6; i++)
    {
        asientos[i-1] = i;
    }
    
    for (int i = 0; i < cambios; i++)
    {
        int orig, dest;
        cin >> orig >> dest;
        orig--;
        dest--;
        
        if (orig / 6 <= dest / 6) {
            int aux = asientos[orig];
            asientos[orig] = asientos[dest];
            asientos[dest] = aux;
        } else {
            if (orig % 2 == 0) {
                orig++;
            } else {
                orig--;
            }
            if (dest % 2 == 0) {
                dest++;
            } else {
                dest--;
            }
            int aux = asientos[orig];
            asientos[orig] = asientos[dest];
            asientos[dest] = aux;
        }
    }

    for (int i = 0; i < filas; i++)
    {
        cout << asientos[i*6];
        for (int j = 1; j < 6; j++)
        {
            cout << " " << asientos[i*6 + j];
        }
        cout << endl;
    }

    cout << "---" << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}