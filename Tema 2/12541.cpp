#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Persona {
    public:
        string name;
        int day, month, year;
        Persona(string n, int d, int m, int y) {
            name = n;
            day = d;
            month = m;
            year = y;
        }

        bool operator < (Persona &p) {
            if (year != p.year) return year < p.year;
            if (month != p.month) return month < p.month;
            return day < p.day;
        }
};

void solve() {
    int num;
    cin >> num;

    string name;
    int d, m, y;
    cin >> name >> d >> m >> y;

    vector<Persona> list;
    for (size_t i = 0; i < num; i++)
    {
        cin >> name >> d >> m >> y;
        list.push_back(Persona(name, d, m, y));
    }
    sort(list.begin(), list.end());

    cout << list.back().name << endl;
    cout << list[0].name << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}