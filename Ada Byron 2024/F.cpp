#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<long, int> indexMago;

void solve() {
    int n;
    cin >> n;
    long long magos[n] = {0};

    indexMago.clear();

    for (int i = 0; i < n; i++)
    {
        cin >> magos[i];
        indexMago[magos[i]] = i;
    }

    sort(magos, magos+n);

    long long sum[n] = {0};
    sum[0] = magos[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i-1] + magos[i];
        // cout << sum[i] << endl;
    }

    for (int i = n-1; i > 0; i--)
    {
        if (sum[i-1] < magos[i]) {
            //cout << sum[i-1] << endl;
            cout << indexMago[magos[i]]+1 << endl;
            return;
        }
    }
    cout << 1 << endl;

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