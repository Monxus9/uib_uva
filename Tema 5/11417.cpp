#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}

bool solve() {
    int num;
    cin >> num;
    if (num == 0)
        return false;
    else {
        // Code solve

        int g = 0;
        for (size_t i = 1; i < num; i++)
        {
            for (size_t j = i+1; j <= num; j++)
            {
                g += gcd(i,j);
            }
            
        }
        cout << g << endl;
        

    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}