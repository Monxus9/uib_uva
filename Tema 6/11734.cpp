#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int caso;

void solve() {
    string lin1, lin2;
    getline(cin, lin1);
    getline(cin, lin2);

    int idx1 = 0, idx2 = 0;
    char c1, c2;
    bool valid = true;
    bool spaces = false;
    while (idx1 < lin1.length() && idx2 < lin2.length()) {
        c1 = lin1[idx1++];
        c2 = lin2[idx2++];
        if (c1 == c2) continue;
        spaces = true;
        while (c1 == ' ' && idx1 < lin1.length()) {
            c1 = lin1[idx1++];
        }
        while (c2 == ' ' && idx2 < lin2.length()) {
            c2 = lin2[idx2++];
        }
        // cout << "c1 " << c1 << " c2 " << c2 << endl;
        if (c1 != c2) {
            valid = false;
            break;
        }

    }

    if (valid) {
        while(idx1 < lin1.length()) {
            spaces = true;
            c1 = lin1[idx1++];
            if (c1 != ' ') {
                valid = false;
                break;
            }
        }
        while(idx2 < lin2.length()) {
            spaces = true;
            c2 = lin2[idx2++];
            if (c2 != ' ') {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        printf("Case %d: Wrong Answer\n", caso);
    } else {
        if (spaces) {
            printf("Case %d: Output Format Error\n", caso);
        } else {
            printf("Case %d: Yes\n", caso);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    cin.ignore();
    caso = 1;
    while(casos--) {
        solve();
        caso++;
    }
  
    return 0;
}