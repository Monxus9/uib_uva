#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    string line;

    if (getline(cin, line)) {
        list<char> sol;
        list<char>::iterator iter(sol.begin()); // Iterador
        int indexInsert = 0;
        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            if (c == '[') {
                iter = sol.begin();
            } else if (c == ']') {
                iter = sol.end();
            } else {
                sol.insert(iter, c);
            }
        }
        copy(sol.begin(), sol.end(), ostream_iterator<char>(cout, "")); // Transformar sol en string
        cout << endl;
        return true;
    }
    return false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}