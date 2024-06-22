#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int caso;

class Salto {
    public:
        int dest, peso;
        Salto(int d, int p) {
            dest = d;
            peso = p;
        }

        bool operator<(const Salto &other) const {
            return peso > other.peso;
        }
};

bool solve() {
    int size;
    cin >> size;
    if (size == 0)
        return false;
    else {
        // Code solve
        map<int, vector<int>> nodos;

        int idx1, idx2;
        for (size_t i = 0; i < size; i++)
        {
            cin >> idx1 >> idx2;
            nodos[idx1].push_back(idx2);
            nodos[idx2].push_back(idx1);
        }
        // cout << nodos.size() << endl;

        int inicio, ttl;
        cin >> inicio >> ttl;
        while (!(inicio == 0 && ttl == 0)) {
            // cout << inicio << " " << ttl << endl;

            unordered_set<int> visitados;
            priority_queue<Salto> pq;
            pq.push(Salto(inicio,0));

            while (!pq.empty()) {
                Salto salto = pq.top();
                pq.pop();
                if (salto.peso > ttl) break;
                idx1 = salto.dest;
                if (visitados.find(idx1) != visitados.end()) continue;
                visitados.insert(idx1);

                for (size_t j = 0; j < nodos[idx1].size(); j++)
                {
                    pq.push(Salto(nodos[idx1][j], salto.peso + 1));
                }

            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caso++, (nodos.size() - visitados.size()), inicio, ttl);
            cin >> inicio >> ttl;
        }

    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    caso = 1;
    while(solve()) {
    }
  
    return 0;
}