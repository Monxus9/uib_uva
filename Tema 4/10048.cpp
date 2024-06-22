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

bool solve() {
    int num_nodos, num_aristas, preguntas;
    cin >> num_nodos >> num_aristas >> preguntas;
    if (num_nodos == 0 && num_aristas == 0 && preguntas == 0)
        return false;
    else {
        if (casos != 1) {
            printf("\n");
        }
        printf("Case #%d\n", casos);
        vector<vector<Arista>> nodos;
        nodos.resize(num_nodos+1);

        for (size_t i = 0; i < num_aristas; i++)
        {
            int idx1, idx2, peso;
            cin >> idx1 >> idx2 >> peso;
            nodos[idx1].push_back(Arista(idx2, peso));
            nodos[idx2].push_back(Arista(idx1, peso));
            // cout << idx1 << " " << idx2 << " " << peso << endl;
        }

        for (size_t i = 0; i < preguntas; i++)
        {
            int idx1, idx2;
            int total = 0;
            cin >> idx1 >> idx2;

            unordered_set<int> visitados;
            priority_queue<Arista> pq;

            visitados.insert(idx1);
            for (size_t j = 0; j < nodos[idx1].size(); j++)
            {
                pq.push(nodos[idx1][j]);
            }

            bool encontrado = false;
            while(!pq.empty()) {
                Arista ari = pq.top();
                pq.pop();
                idx1 = ari.dest;
                if (visitados.find(idx1) != visitados.end()) continue;
                visitados.insert(idx1);
                total = max(total, ari.peso);
                if (idx1 == idx2) {
                    encontrado = true;
                    break;
                }

                for (size_t j = 0; j < nodos[idx1].size(); j++)
                {
                    pq.push(nodos[idx1][j]);
                }

            }

            if (!encontrado) {
                printf("no path\n");
            } else {
                printf("%d\n", total);
            }
            
        }

    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    casos = 1;
    while(solve()) {
        casos++;
    }
  
    return 0;
}