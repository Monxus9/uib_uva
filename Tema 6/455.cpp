#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    string line;
    getline(cin, line);
    getline(cin, line);

    bool end;
    for (size_t i = 1; i < line.length(); i++)
    {
        end = false;
        if (line.length() % i == 0) {
            end = true;
            for (size_t j = 0; j < i && end; j++)
            {
                for (size_t k = j+i; k < line.length() && end; k+=i)
                {
                    end = line[j] == line[k];
                }
                
            }
            
        }
        if (end) {
            cout << i << endl;
            return;
        }
    }
    cout << line.length() << endl;
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    cin.ignore();

    while(casos--) {
        solve();
        if (casos != 0) {
            cout << endl;
        }
    }
  
    return 0;
}