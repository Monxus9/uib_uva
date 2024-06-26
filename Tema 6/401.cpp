#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

map<char, char> mirror;

bool solve() {
    string line;

    if (getline(cin, line)) {
        bool is_pal = true, is_mirr = true;

        int last_index = line.length()-1;
        for (size_t i = 0; i < (line.length()/2)+1; i++)
        {
            if (is_pal) {
                is_pal = line[i] == line[last_index-i];
            }
            if (is_mirr) {
                if (mirror.find(line[i]) == mirror.end()) {
                    is_mirr = false;
                } else {
                    is_mirr = mirror[line[i]] == line[last_index-i];
                }
            }
        }

        if (is_pal && is_mirr) {
            cout << line << " -- is a mirrored palindrome." << endl;
        } else if (is_pal && !is_mirr) {
            cout << line << " -- is a regular palindrome." << endl;
        } else if (!is_pal && is_mirr) {
            cout << line << " -- is a mirrored string." << endl;
        } else {
           cout << line << " -- is not a palindrome." << endl;
        }
        cout << endl;
        

        return true;
        
    }

    return false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';

    while(solve()) {
    }
  
    return 0;
}