#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string line;
    getline(cin, line);
    if (line == "0") return false;
    int base = 1;

    int num = 0;
    for (int i = line.length()-1; i >= 0; i--)
    {
        num += (base * (line[i] - '0'));
        base++;
        base *= 2;
        base--;
    }
    cout << num << endl;
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}