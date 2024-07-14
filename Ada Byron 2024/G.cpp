#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Examen {
    public:
        int min, max, nota, idx;
        Examen(int mi, int ma, int n, int i) {
            min = mi;
            max = ma;
            nota = n;
            idx = i;
        }

        bool operator<(const Examen &other) const {
            if (nota == other.nota) return idx > other.idx;
            return nota > other.nota;
        }
};



bool solve() {
    int estudiantes, examenes;
    if (!(cin >> estudiantes)) return false;
    cin >> examenes;

    int total[examenes] = {0};

    for (int i = 0; i < estudiantes; i++)
    {
        for (int j = 0; j < examenes; j++)
        {
            int nota;
            cin >> nota;
            total[j]+=nota;
        }
        
    }

    int acc = 0;
    int porcentaje[examenes] = {0};
    priority_queue<Examen> all;
    for (int i = 0; i < examenes; i++)
    {
        int minim, maxim;
        cin >> minim >> maxim;
        porcentaje[i] = minim;
        acc += minim;
        all.push(Examen(minim, maxim, total[i], i));
    }

    while (acc < 100) {
        Examen ex = all.top();
        // cout << ex.nota << endl;
        all.pop();
        int diff = ex.max - ex.min;
        if (acc + diff > 100) {
            diff = 100 - acc;
            porcentaje[ex.idx] += diff;
        } else {
            porcentaje[ex.idx] = ex.max;
        }
        acc += diff;
    }

    cout <<  porcentaje[0];
    for (int i = 1; i < examenes; i++)
    {
        cout << " " << porcentaje[i];
    }
    cout << endl;
    
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}