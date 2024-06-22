#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int num;

    if (!(cin >> num)) {
        return false;
    }
    int coches[num] = {0};
    int final[num] = {0};

    for (size_t i = 0; i < num; i++)
    {
        cin >> coches[i];
    }

    for (size_t i = 0; i < num; i++)
    {
        cin >> final[i];
    }

    int intercambios = 0;

    for (size_t i = num-1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (coches[j] == final[i]) {
                coches[j] = coches[j+1];
                coches[j+1] = final[i];
                intercambios++;
            }
        }
        
    }
    
    cout << intercambios << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}