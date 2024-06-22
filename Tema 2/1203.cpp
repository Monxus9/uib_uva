#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Elem {
    public:
        int year, interval, next;
        Elem(int y, int i, int n) {
            year = y;
            interval = i;
            next = n;
        }

        bool operator<(const Elem &other) const {
            if (next != other.next) return next > other.next;
            return year > other.year;
        }
};


void solve() {
    string dummy;
    int n1, n2;

    cin >> dummy;
    priority_queue<Elem> pq;

    while (dummy != "#") {
        cin >> n1 >> n2;

        pq.push(Elem(n1,n2,n2));

        cin >> dummy;
    }
    cin >> n1;

    for (size_t i = 0; i < n1; i++)
    {
        Elem elem = pq.top();
        pq.pop();

        cout << elem.year << endl;

        
        pq.push(Elem(elem.year, elem.interval, elem.next + elem.interval));
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

  
    return 0;
}