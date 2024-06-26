#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    string lin1, lin2;

    if (getline(cin, lin1)) {
        getline(cin, lin2);
        vector<vector<int>> memo;
        memo.resize(lin1.length()+1);
        for (size_t i = 0; i < lin1.length()+1; i++)
        {
            memo[i].resize(lin2.length()+1);
            fill( memo[i].begin(), memo[i].end(), 0);
        }

        for (size_t i = 1; i <= lin1.length(); i++)
        {
            for (size_t j = 1; j <= lin2.length(); j++)
            {
                if (lin1[i-1] == lin2[j-1]) {
                    memo[i][j] = 1 + memo[i-1][j-1];
                } else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
            
        }

        cout << memo[lin1.length()][lin2.length()] << endl;
        
        
        
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