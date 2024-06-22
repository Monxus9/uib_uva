#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    int m, n;
    cin >> m >> n;
    if (m == 0) return false;
    cin.ignore();
    vector<vector<bool>> nodes;
    nodes.resize(m);

    string line;
    for (size_t i = 0; i < m; i++)
    {
        getline(cin, line);
        for (size_t j = 0; j < n; j++)
        {
            nodes[i].push_back(line[j] == '@');
        }
        
    }

    unordered_set<int> visitados;
    int total = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (!nodes[i][j]) continue;
            int code = i * n + j;
            if (visitados.find(code) != visitados.end()) continue; 

            queue<int> cola;
            cola.push(code);
            total++;

            while (!cola.empty()) {
                int idx = cola.front();
                cola.pop();
                if (visitados.find(idx) != visitados.end()) continue; 
                visitados.insert(idx);

                int row = idx / n;
                int col = idx % n;

                if (row > 0) {
                    if (col > 0 && nodes[row-1][col-1]) {
                        cola.push((row-1) * n + col - 1);
                    }
                    if (nodes[row-1][col]) {
                        cola.push((row-1) * n + col);
                    }
                    if (col < n-1 && nodes[row-1][col+1]) {
                        cola.push((row-1) * n + col + 1);
                    }
                }

                if (col > 0 && nodes[row][col-1]) {
                    cola.push((row) * n + col - 1);
                }

                if (col < n-1 && nodes[row][col+1]) {
                    cola.push((row) * n + col + 1);
                }


                if (row < m-1) {
                    if (col > 0 && nodes[row+1][col-1]) {
                        cola.push((row+1) * n + col - 1);
                    }
                    if (nodes[row+1][col]) {
                        cola.push((row+1) * n + col);
                    }
                    if (col < n-1 && nodes[row+1][col+1]) {
                        cola.push((row+1) * n + col + 1);
                    }
                }

            
            }

        }
    }
    
    cout << total << endl;

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}