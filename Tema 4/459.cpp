#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    char last_char;
    cin >> last_char;
    cin.ignore();

    vector<vector<int>> nodes;
    nodes.resize(last_char - 'A' + 1);

    string line;
    while (getline(cin, line) && line != ""){
        nodes[line[0]-'A'].push_back(line[1]-'A');
        nodes[line[1]-'A'].push_back(line[0]-'A');
    }

    unordered_set<int> visitados;
    int total = 0;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        queue<int> cola;
        if (visitados.find(i) != visitados.end()) continue; 
        
        cola.push(i);
        while (!cola.empty()) {
            int idx = cola.front();
            cola.pop();
            if (visitados.find(idx) != visitados.end()) continue; 
            visitados.insert(idx);
            for (size_t j = 0; j < nodes[idx].size(); j++)
            {
                cola.push(nodes[idx][j]);
            }
            
        }
        
        total++;
        
    }
    
    cout << total << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    while(casos--) {
        solve();
        if (casos != 0) {
            cout << endl;
        }
    }
  
    return 0;
}