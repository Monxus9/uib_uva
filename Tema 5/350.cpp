#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int z, i, m, l;
int caso;

int next_random(int last) {
    return (z * last + i) % m;
}


bool solve() {
    
    cin >> z >> i >> m >> l;
    if (z == 0 && i == 0 && m == 0 && l == 0) return false;

    // Floyd
    int tortuga = l, liebre = l;
    do {
        //cout << "1" << endl;
        tortuga = next_random(tortuga);
        liebre = next_random(next_random(liebre)); // La liebre avanza de dos en dos
    } while (tortuga != liebre);

    // Avanza la tortuga, la liebre quieta
    int count = 0;
    do {
        //cout << "2" << endl;
        tortuga = next_random(tortuga);
        count++;
    } while (tortuga != liebre);


    printf("Case %d: %d\n", caso, count);


    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    caso = 1;
    while(solve()) {
        caso++;
    }
  
    return 0;
}