#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int casos;

bool solve() {
    int idx1, idx2;
    cin >> idx1 >> idx2;
    if (idx1 == 0 && idx2 == 0)
        return false;
    else {
        // Code solve
        vector<vector<int>> nodos;
        unordered_set<int> visitados;
        vector<int> idx_nodos;


        nodos.resize(101);
        for (size_t i = 0; i <= 100; i++)
        {
            nodos[i].resize(101);
            fill(nodos[i].begin(), nodos[i].end(), 99999);
        }
        

        while (!(idx1 == 0 && idx2 == 0)) {
            if (visitados.find(idx1) == visitados.end()) {
                visitados.insert(idx1);
                idx_nodos.push_back(idx1);
            }
            if (visitados.find(idx2) == visitados.end()) {
                visitados.insert(idx2);
                idx_nodos.push_back(idx2);
            }
            nodos[idx1][idx2] = 1;
            cin >> idx1 >> idx2;
        }
        

        int size = idx_nodos.size();

        int idxI, idxJ, idxK;
        for (size_t i = 0; i < size; i++)
        {
            idxI = idx_nodos[i];
            for (size_t j = 0; j < size; j++)
            {
                idxJ = idx_nodos[j];
                for (size_t k = 0; k < size; k++)
                {
                    idxK = idx_nodos[k];
                    if (idxJ == idxK) {
                        nodos[idxJ][idxK] = 0;
                    }
                    nodos[idxJ][idxK] = min(nodos[idxJ][idxK], nodos[idxJ][idxI] + nodos[idxI][idxK]);
                }
            }
            
        }

        double sum, count;
        sum = 0;
        count = 0;
        for (size_t i = 0; i < size; i++)
        {
            idxI = idx_nodos[i];
            for (size_t j = 0; j < size; j++)
            {
                idxJ = idx_nodos[j];
                if (idxI != idxJ && nodos[idxI][idxJ] != 99999) {
                    // cout << idxI << idxJ << endl;
                    sum += nodos[idxI][idxJ];
                    count++;
                };
            }
            
        }
        //cout << sum << endl;
        //cout << count << endl;
        printf("Case %d: average length between pages = %.3f clicks\n", casos, (sum/count));
        
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