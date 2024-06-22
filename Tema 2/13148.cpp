#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    unordered_set<int> my_set;
    my_set.insert(1);
    my_set.insert(64);
    my_set.insert(729);
    my_set.insert(4096);
    my_set.insert(15625);
    my_set.insert(46656);
    my_set.insert(117649);
    my_set.insert(262144);
    my_set.insert(531441);
    my_set.insert(1000000);
    my_set.insert(1771561);
    my_set.insert(2985984);
    my_set.insert(4826809);
    my_set.insert(7529536);
    my_set.insert(11390625);
    my_set.insert(16777216);
    my_set.insert(24137569);
    my_set.insert(34012224);
    my_set.insert(47045881);
    my_set.insert(64000000);
    my_set.insert(85766121);
    int num;
    cin >> num;

    while (num != 0) {
        if (my_set.find(num) == my_set.end()) {
            cout << "Ordinary" << endl;
        } else {
            cout << "Special" << endl;
        }

        cin >> num;

    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}