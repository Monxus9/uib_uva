// Este código NO resuelve el problema, es un planteamiento, pero falla en algunos casos

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX - 1;

int n_nodos, n_aristas, max_edificios;
int ori_inicio, dest_final;
vector<vector<pair<int, pair<int, int>>>> nodos; // {destination, {time, buildings}}
vector<double> ratios;

class Ruta {
    public:
        int idxNodo;
        double ratio;
        Ruta(int i, double r) {
            idxNodo = i;
            ratio = r;
        }

        bool operator<(const Ruta &other) const {
            return ratio < other.ratio;
        }
};

double calculaGrafo(double rat) {
    priority_queue<Ruta> rutas;
    ratios = vector<double>(n_nodos + 1, -INF);
    unordered_set<int> visitados;

    for (int i = 0; i < nodos[ori_inicio].size(); i++)
    {
        double weight = nodos[ori_inicio][i].second.second - (rat * nodos[ori_inicio][i].second.first);
        rutas.push(Ruta(nodos[ori_inicio][i].first, weight));
        ratios[nodos[ori_inicio][i].first] = weight;
    }
    visitados.insert(ori_inicio);

    while (!rutas.empty()) {
        
        Ruta myruta = rutas.top();
        // cout << "MR: " << myruta.idxNodo << " " << myruta.ratio << endl;
        rutas.pop();
        int idx = myruta.idxNodo;
        if (idx == dest_final) break;
        if (visitados.find(idx) != visitados.end()) continue;
        visitados.insert(idx);

        for (int i = 0; i < nodos[idx].size(); i++)
        {
            double weight = nodos[idx][i].second.second - (rat * nodos[idx][i].second.first);
            int next_nodo = nodos[idx][i].first;
            if (ratios[idx] + weight > ratios[next_nodo]) {
                ratios[next_nodo] = ratios[idx] + weight;
                
            }
            rutas.push({next_nodo, ratios[next_nodo]});
        }

    }
    //cout << "Ratio: " << rat << " " << ratios[dest_final] << endl;

    return ratios[dest_final];
}

double busquedaBinaria(double left, double right) {
    double mid = 0;
    while (right - left > 1e-7) {
        mid = (right + left) / 2;
        if (calculaGrafo(mid) >= 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}

bool solve() {
    if (!(cin >> n_nodos)) return false;
    cin >> n_aristas;

    nodos = vector<vector<pair<int, pair<int, int>>>>(n_nodos + 1);

    int ori, des, time, edif;

    for (int i = 0; i < n_aristas; i++) {
        cin >> ori >> des >> time >> edif;
        max_edificios += edif;
        nodos[ori].push_back({des, {time, edif}});
        nodos[des].push_back({ori, {time, edif}});
    }

    int consultas;
    cin >> consultas;
    for (int i = 0; i < consultas; i++) {
        cin >> ori_inicio >> dest_final;
        printf("%.6f\n", busquedaBinaria(0, max_edificios));
    }
    printf("---\n");

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (solve()) {}

    return 0;
}
