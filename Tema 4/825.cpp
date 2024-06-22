#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix;
    matrix.resize(rows+1);
    cin.ignore();

    string line;
    int row, col;
    matrix[0].resize(cols+1);
    fill(matrix[0].begin(), matrix[0].end(), 0);
    for (size_t i = 1; i <= rows; i++)
    {
        matrix[i].resize(cols+1);
        fill(matrix[i].begin(), matrix[i].end(), 0);


        getline(cin, line);
        stringstream cin2(line);
        cin2 >> row;
        while(cin2 >> col) {
            matrix[row][col] = -1;
        }
    }

    if (matrix[1][1] == -1) {
        cout << 0 << endl;
        return;
    }
    matrix[1][1] = 1;

    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= cols; j++)
        {
            if (matrix[i][j] == -1) continue;
            if (matrix[i-1][j] != -1) {
                matrix[i][j] += matrix[i-1][j];
            }
            if (matrix[i][j-1] != -1) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
    }
    
    cout <<  matrix[rows][cols] << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    while(casos--) {
        solve();
        if (casos != 0) {
            cout << endl;
        }
    }
  
    return 0;
}