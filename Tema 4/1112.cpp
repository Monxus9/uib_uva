#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int casos;

class Arista {
    public:
        int dest, peso;
        Arista(int d, int p) {
            dest = d;
            peso = p;
        }

        bool operator<(const Arista &other) const {
            return peso > other.peso;
        }
};

void solve() {
    int num_nodos, fin, ttl, num_aristas;
    cin >> num_nodos >> fin >> ttl >> num_aristas;

    vector<vector<Arista>> nodos;
    nodos.resize(num_nodos+1);

    for (size_t i = 0; i < num_aristas; i++)
    {
        int idx1, idx2, peso;
        cin >> idx1 >> idx2 >> peso;
        nodos[idx2].push_back(Arista(idx1, peso));
        // cout << idx1 << " " << idx2 << " " << peso << endl;
    }

    unordered_set<int> visitados;
    priority_queue<Arista> pq;

    visitados.insert(fin);
    for (size_t j = 0; j < nodos[fin].size(); j++)
    {
        pq.push(nodos[fin][j]);
    }

    while(!pq.empty()) {
        Arista ari = pq.top();
        pq.pop();
        
        if (ari.peso > ttl) {
            break;
        }
        int idx = ari.dest;
        if (visitados.find(idx) != visitados.end()) continue;
        visitados.insert(idx);

        for (size_t j = 0; j < nodos[idx].size(); j++)
        {
            pq.push(Arista(nodos[idx][j].dest,nodos[idx][j].peso + ari.peso));
        }

    }
    printf("%d\n", visitados.size());

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    while(casos--) {
        solve();
        if (casos > 0) {
            printf("\n");
        }
    }
  
    return 0;
}