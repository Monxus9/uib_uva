#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    string line;
    getline(cin, line);
    int count[26] = {0};
    int max = 0;
    int idx = 0;
    //cout << line << endl;
    for (size_t i = 0; i < line.length(); i++)
    {
        char c = line[i];
        idx = -1;
        if (c >= 'a' && c <= 'z') {
            idx = c - 'a';
        }
        if (c >= 'A' && c <= 'Z') {
            idx = c - 'A';
        }
        if (idx > -1) {
            count[idx]++;
            if (count[idx] > max) {
                max = count[idx];
            }
        }
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (count[i] == max) {
            char c = i + 'a';
            cout << c;
        }
    }
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    string dummy;
    getline(cin, dummy);

    while(casos--) {
        solve();
    }
  
    return 0;
}