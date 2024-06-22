#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int memo[7490] = {0};
    int coins[5] = {1,5,10,25,50};

    memo[0] = 1;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 1; j < 7490; j++)
        {
            if (coins[i] <= j) {
                memo[j] += memo[j - coins[i]];
                // cout << j << ": " << memo[j] << endl;
            }
        }
        
    }
    

    int num;
    while(cin >> num) {
        cout << memo[num] << endl;
    }
  
    return 0;
}