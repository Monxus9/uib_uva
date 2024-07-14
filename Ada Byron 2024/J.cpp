#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const string memo[10][7] = {
        {".##.", "#..#", "#..#", "....", "#..#", "#..#", ".##."},
        {"....", "...#", "...#", "....", "...#", "...#", "...."},
        {".##.", "...#", "...#", ".##.", "#...", "#...", ".##."},
        {".##.", "...#", "...#", ".##.", "...#", "...#", ".##."},
        {"....", "#..#", "#..#", ".##.", "...#", "...#", "...."},
        {".##.", "#...", "#...", ".##.", "...#", "...#", ".##."},
        {".##.", "#...", "#...", ".##.", "#..#", "#..#", ".##."},
        {".##.", "...#", "...#", "....", "...#", "...#", "...."},
        {".##.", "#..#", "#..#", ".##.", "#..#", "#..#", ".##."},
        {".##.", "#..#", "#..#", ".##.", "...#", "...#", ".##."}
    };
bool solve() {
    int size;
    cin >> size;
    cin.ignore();
    if (size == 0) return false;

    string lines[9];

    for (int i = 0; i < 9; i++)
    {
        getline(cin, lines[i]);
    }
    
    vector<vector<bool>> valids(size, vector<bool>(10, true));
    int sum[size] = {0};

    int mult = 1;

    for (int i = 0; i < size; i++)
    {
        sum[i] = 10;
        for (int fila = 0; fila < 9; fila++)
        {
            for (int col = i*6; col < (i+1)*6; col++)
            {
                if (lines[fila][col] == 'X') continue;
                if (fila == 0 || fila == 8 || col == i*6 || col == i*6+5) {
                    if (lines[fila][col] == '#') {
                        cout << 0 << endl;
                        return true;
                    }
                } else {
                    
                    for (int num = 0; num < 10; num++)
                    {
                        if (!valids[i][num]) continue;
                        if (memo[num][fila-1][(col%6)-1] != lines[fila][col]) {
                            sum[i]--;
                            valids[i][num] = false;
                            //cout << num << ": " << fila << " " << col << endl;
                            if (sum[i] == 0) {
                                cout << 0 << endl;
                                return true;
                            }
                        }
                        
                    }
                    
                }
            }
            
        }
        mult *= sum[i];
        // cout << "-->" << sum[i] << endl;
    }

    cout << mult << endl;
    



    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}