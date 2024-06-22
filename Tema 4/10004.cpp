#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    int size;
    cin >> size;
    if (size == 0) return false;
    int cases;
    cin >> cases;

    vector<vector<int>> nodes;
    int colores[size] = {0};
    nodes.resize(size);

    int idx1, idx2;
    for (size_t i = 0; i < cases; i++)
    {
        cin >> idx1 >> idx2;
        nodes[idx1].push_back(idx2);
        nodes[idx2].push_back(idx1);
    }

    unordered_set<int> visitados;
    bool valid = true;


        queue<int> cola;
        cola.push(0);
        colores[0] = 1;
        while (!cola.empty() && valid) {
            int idx = cola.front();
            cola.pop();
            if (visitados.find(idx) != visitados.end()) continue; 
            visitados.insert(idx);
            for (size_t j = 0; j < nodes[idx].size() && valid; j++)
            {
                int idx2 = nodes[idx][j];
                if (colores[idx2] == 0) {
                    colores[idx2] = -colores[idx];
                } else {
                    valid = colores[idx2] == -colores[idx];
                }

                cola.push(idx2);
            }
            
        }

    
    if (valid) {
        printf("BICOLORABLE.\n");
    } else {
        printf("NOT BICOLORABLE.\n");
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(solve()) {
        // solve();
    }
  
    return 0;
}