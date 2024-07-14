#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string line, busq;
int x, y, xSol, ySol;

int buscaIzq (int left, int right) {
    int med = (left+right)/2;
    cout << "? " << med << " " << y << endl;
    getline(cin, busq);
    if (busq == "IND") return med;
    if (busq == line) {
        return buscaIzq(left, med-1);
    } else {
        return buscaIzq(med+1, right);
    }
}

int buscaDer (int left, int right) {
    int med = (left+right)/2;
    cout << "? " << med << " " << y << endl;
    getline(cin, busq);
    if (busq == "IND") return med;
    if (busq != line) {
        return buscaDer(left, med-1);
    } else {
        return buscaDer(med+1, right);
    }
}

int buscaAbajo (int down, int up) {
    int med = (down+up)/2;
    cout << "? " << x << " " << med << endl;
    getline(cin, busq);
    if (busq == "IND") return med;
    if (busq == line) {
        return buscaAbajo(down, med-1);
    } else {
        return buscaAbajo(med+1, up);
    }
}

int buscaArriba (int down, int up) {
    int med = (down+up)/2;
    cout << "? " << x << " " << med << endl;
    getline(cin, busq);
    if (busq == "IND") return med;
    if (busq != line) {
        return buscaArriba(down, med-1);
    } else {
        return buscaArriba(med+1, up);
    }
}


void buscaNS() {
    int izq = buscaIzq(-999999999, x-1);
    int der = buscaDer(x+1, 999999999);

    xSol = (izq+der)/2;
    if (line == "N") {
        ySol = (der+y) - xSol;
    } else {
        ySol = (izq+y) - xSol;
    }
}

void buscaOE() {
    int abajo = buscaAbajo(-999999999, y-1);
    int arriba = buscaArriba(y+1, 999999999);

    ySol = (arriba+abajo)/2;
    if (line == "E") {
        xSol = (arriba+x) - ySol;
    } else {
        xSol = (abajo+x) - ySol;
    }

}

bool solve() {
    if (!(cin >> x)) return false;
    cin >> y;
    cin.ignore();

    cout << "? " << x << " " << y << endl;

    getline(cin, line);

    while (line == "IND") {
        x++;
        cout << "? " << x << " " << y << endl;

        getline(cin, line);
    }
    
    if (line == "N" || line == "S")  {
        buscaNS();
    } else {
        buscaOE();
    }
    cout << "Respuesta: " << xSol << " " << ySol << endl;

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}