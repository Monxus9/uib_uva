#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int counter;

void solve() {
    int size;
    cin >> size;

    int arr[size];

    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int min = arr[0];
    int max = arr[size-1];
    int last_valid = max;

    while (min <= max) {
        int med = (min + max) / 2;

        int value = med;
        if (value == arr[0]) {
            value--;
        }

        bool valid = true;
        for (size_t i = 1; i < size && valid; i++)
        {
            int diff = arr[i] - arr[i-1];
            if (value == diff) {
                value--;
            } else if (value < diff) {
                valid = false;
            }
        }
        if (!valid) {
            min = med + 1;
        } else {
            last_valid = med;
            max = med - 1;
        }
    }

    printf("Case %d: %d\n", counter, last_valid);
    



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    counter = 1;
    while(casos--) {
        
        solve();
        counter++;
    }
  
    return 0;
}