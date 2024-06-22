#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    int size;
    cin >> size;
    int items[size];

    for (size_t i = 0; i < size; i++)
    {
        cin >> items[i];
    }

    sort(items, items+size);

    int start_index = size % 3;
    int sum = 0;
    while (start_index <= size-3) {
        sum += items[start_index];
        start_index += 3;
    }
    cout << sum << endl;
    

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