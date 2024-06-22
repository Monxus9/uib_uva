#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    int size;
    cin >> size;

    int arr[size];

    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int coins = 1;
    int acc = 0;

    for (size_t i = 0; i < size - 1; i++)
    {
        if (acc + arr[i] < arr[i+1]) {
            coins++;
            acc += arr[i];
        }
    }
    cout << coins << endl;

    

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