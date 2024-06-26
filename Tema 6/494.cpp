#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    string line;

    if (getline(cin, line)) {

        bool palabra = false;
        int count = 0;
        for (size_t i = 0; i < line.length(); i++)
        {
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
                palabra = true;
            } else {
                if (palabra) {
                    count++;
                    palabra = false;
                }
            }
        }

        if (palabra) {
            count++;
        }
        cout << count << endl;
        
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