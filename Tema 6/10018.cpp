#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long reverse(long num) {
    long num2 = 0;
    while (num > 0) {
        num2 *= 10;
        num2 += (num % 10);
        num /= 10;
    }
    return num2;

}

void solve() {
    long num, numAux;
    cin >> num;
    int iters = 0;

    numAux = reverse(num);

    while(numAux != num) {
        num += numAux;
        iters++;

        numAux = reverse(num);
    }

    cout << iters << " " << num << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    while(casos--) {
        solve();
    }
  
    return 0;
}