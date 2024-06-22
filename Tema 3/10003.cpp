#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<int>> memo;

int best(int izq, int der) {
    if (memo[izq][der] != -1) return memo[izq][der];
    if (izq + 1 >= der) return 0;

    int cost = 999999999;
    for (size_t i = izq+1; i <= der-1; i++)
    {
        cost = min(cost, best(izq, i) + best(i, der) + arr[der] - arr[izq]);
    }
    memo[izq][der] = cost;
    // cout << izq << "-" << der << ": " << cost << endl;
    return cost;
}

bool solve() {
    int lon;
    cin >> lon;
    if (lon == 0)
        return false;
    else {
        // Code solve
        int size;
        cin >> size;
        
        memo.resize(size+2);
        // Memoria a 0
        for (size_t i = 0; i < size+2; i++)
        {
            vector<int> memo2(size+2);
            fill(memo2.begin(), memo2.end(), -1);
            memo[i] = memo2;
        }

        arr.resize(size+2);
        arr[0] = 0;
        arr[size+1] = lon;
        for (size_t i = 1; i <= size; i++)
        {
            cin >> arr[i];
        }

        int mejor = best(0,size+1);
        printf("The minimum cutting is %d.\n", mejor);        

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