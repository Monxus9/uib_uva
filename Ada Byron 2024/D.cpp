#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    int letras[30] = {0};
    int min = 1;
    int max = 0;

    for (int i = 0; i < line.length(); i++)
    {
        int idx = line[i] - 'a';
        letras[idx]++;
        if (max < letras[idx]) max = letras[idx];
    }

    bool valid = true;
    for (int i = 0; i < 30 ; i++)
    {
        if (letras[i] != 0) {
            if (letras[i] != max) valid = false;
        }
    }
    
    if (valid) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    cin.ignore();

    while(casos--) {
        solve();
    }
  
    return 0;
}