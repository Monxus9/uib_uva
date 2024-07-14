#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Ruta {
    public:
        int idxNodo, maxAncho;
        Ruta(int i, int a) {
            idxNodo = i;
            maxAncho = a;
        }

        bool operator<(const Ruta &other) const {
            return maxAncho < other.maxAncho;
        }
};

bool solve() {
    int nNodos, nAristas;
    if (!(cin >> nNodos)) return false;
    cin >> nAristas;

    vector<vector<pair<int, int>>> nodos;

    nodos.resize(nNodos+1);

    // Leer nodos
    int orig, dest, ancho;
    for (int i = 0; i < nAristas; i++)
    {
        cin >> orig >> dest >> ancho;
        pair<int,int> arista(dest,ancho);
        nodos[orig].push_back(arista);
    }

    // Dijkstra
    unordered_set<int> visitados;
    priority_queue<Ruta> rutas;

    cin >> orig >> dest;

    visitados.insert(orig);
    for (int i = 0; i < nodos[orig].size(); i++)
    {
        rutas.push(Ruta(nodos[orig][i].first, nodos[orig][i].second));
    }

    while (!rutas.empty()) {
        Ruta mi_ruta = rutas.top();
        rutas.pop();
        int idx = mi_ruta.idxNodo;
        //cout << idx << ": " << mi_ruta.maxAncho << endl;
        if (idx == dest) {
            cout << mi_ruta.maxAncho << endl;
            return true;
        }
        if (visitados.find(idx) != visitados.end()) continue;
        visitados.insert(idx);
        for (int i = 0; i < nodos[idx].size(); i++)
        {
            int ancho = nodos[idx][i].second;
            if (ancho > mi_ruta.maxAncho) {
                ancho = mi_ruta.maxAncho;
            }
            rutas.push(Ruta(nodos[idx][i].first, ancho));
        }

    }
    cout << 0 << endl;
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}