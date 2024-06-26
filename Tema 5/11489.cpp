#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n_caso;

void solve() {
    string line;
    getline(cin, line);
    vector<int> digits(10, 0);
    
    int sum = 0;
    int nums = line.length();
    for (size_t i = 0; i < line.length(); i++)
    {
        int aux = line[i] - '0';
        digits[aux]++;
        sum += aux;
    }

    bool turn_s = true;

    bool jugo = true;
    while(nums > 0 && jugo) {
        //cout << 0 << endl;
        jugo = false;
        if (nums == 1) {
            // cout << 1 << endl;
            nums--;
            turn_s = !turn_s;
            break;
        }

        for (size_t i = 1; i < 10; i++)
        {
            if (digits[i] > 0 && (sum - i) % 3 == 0) {
                digits[i]--;
                sum -= i;
                turn_s = !turn_s;
                jugo = true;
                nums--;
                break;
            }
        }
        
    }
    
    if (turn_s) {
        printf("Case %d: T\n", n_caso);
    } else {
        printf("Case %d: S\n", n_caso);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    cin.ignore();
    n_caso = 1;

    while(casos--) {
        solve();
        n_caso++;
    }
  
    return 0;
}