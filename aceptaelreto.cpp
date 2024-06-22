#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool solve() {
    int n, num;

    unsigned long long sum1 = 0, sum2 = 0;

    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> num;
        sum1 += num;
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> num;
        sum1 -= num;
    }
    
    num = (long) abs(sum1);

    cout << abs(sum2-sum1) << endl;
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {

    }
  
    return 0;
}