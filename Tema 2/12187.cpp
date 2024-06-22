#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n,r,c,k;
    cin >> n >> r >> c >> k;
    if (n == 0 && r == 0 && c == 0 && k == 0)
        return false;
    else {
        // Code solve
        vector<vector<int>> tierra(r);
        vector<vector<int>> guerra(r);
        for (size_t i = 0; i < r; i++)
        {
            tierra[i] = vector<int>(c);
            guerra[i] = vector<int>(c);
            for (size_t j = 0; j < c; j++)
            {
                cin >> tierra[i][j];
            }
            
        }

        
        // Por cada guerra
        for (size_t l = 0; l < k; l++)
        {
            guerra = tierra;
            // Recorrer cada casilla
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    int aux = tierra[i][j];
                    int rival = (aux+1) % n;

                    if ((i-1) >= 0) {
                        if (tierra[i-1][j] == rival) {
                        guerra[i-1][j] = aux;
                        }
                    }
                    if (i+1 < r) {
                        if (tierra[i+1][j] == rival) {
                        guerra[i+1][j] = aux;
                        }
                    }
                    if (j-1 >= 0) {
                        if (tierra[i][j-1] == rival) {
                        guerra[i][j-1] = aux;
                        }
                    }
                    if (j+1 < c) {
                        if (tierra[i][j+1] == rival) {
                        guerra[i][j+1] = aux;
                        }
                    }
                }
                
            }
            tierra = guerra;
        }

        // Imprimir resultado
        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                cout << tierra[i][j];
                if (j != c-1) {
                    cout << " ";
                }
            }
            cout << endl;
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