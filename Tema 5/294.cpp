#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve() {
    int num1, num2;
    cin >> num1 >> num2;

    int best = 0, max = 0;

    for (int i = num1; i <= num2; i++)
    {
        int raiz = sqrt(i);
        int count_actual = 0;
        for (size_t j = 1; j <= raiz; j++)
        {
            if (i % j == 0) {
                count_actual += 2;
                if (j * j == i) {
                    count_actual--;
                }
            }
        }
        
        if (count_actual > max) {
            best = i;
            max = count_actual;
        }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", num1, num2, best, max);

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