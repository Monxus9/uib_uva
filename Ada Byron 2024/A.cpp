#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long modulo = 1000000007;

bool solve() {
    int dias, maxPersonasDia;
    cin >> dias;
    if (dias == 0) return false;

    // Base
    long long memo[dias+1] = {0};  // Almacenar cuantos cuadrados acaban el día i

    stack<pair<int, int>> pila; // Max pers dia, dia
    pila.push({-1,0});

    long long total = 0;

    // Dia 1
    cin >> maxPersonasDia;
    pila.push({maxPersonasDia, 1});

    // Dia 2 en adelante
    long long acaban, dias_base, altura;
    for (int i = 2; i <= dias; i++)
    {
        cin >> maxPersonasDia;
        while (pila.top().first > maxPersonasDia) {
            pila.pop();
        }
        // Evitar iteraciones
        if (maxPersonasDia < 2) {
            if (pila.top().first == maxPersonasDia) {
                pila.pop();
                pila.push({maxPersonasDia, i});
            }
            if (pila.top().first < maxPersonasDia) {
                pila.push({maxPersonasDia, i});
            }
            continue;
        }

        // Rectangulos de MAX altura que acaban el día i
        dias_base = i - pila.top().second;
        altura = 0;
        int last_day = pila.top().second;
        if (last_day == 0) {
            //cout << "A" << endl;
            // Rectángulo desde el inicio
            dias_base--;
            altura = maxPersonasDia - 1;
        } else {
            // Contorlar size rectángulos
            if (maxPersonasDia > pila.top().first) {
                //cout << "B" << endl;
                if (i - last_day > 1) {
                    //cout << "B1" << endl;
                    altura = maxPersonasDia - 1;
                    dias_base--;
                    last_day++;
                } else if (pila.top().first > 1) {
                    //cout << "B2" << endl;
                    altura = pila.top().first - 1;
                }
            } else {
                //cout << "C" << endl;
                if (maxPersonasDia > 1) {
                    altura = maxPersonasDia - 1;
                }
            }
        }
        
        // Rectangulos anteriores (hasta el día que me marque la pila)
        acaban = (dias_base * altura) % modulo;
        //cout << "Mios: " << acaban << " -->" << dias_base << " " << altura << endl;
        //cout << "Anteriores: " << memo[last_day] << endl;
        acaban = (acaban + memo[last_day]) % modulo;
        memo[i] = acaban;

        total += acaban;
        total %= modulo;

        // Actualizar pila
        if (pila.top().first == maxPersonasDia) {
            pila.pop();
            pila.push({maxPersonasDia, i});
        }
        if (pila.top().first < maxPersonasDia) {
            pila.push({maxPersonasDia, i});
        }

        //cout << i << ": " << acaban << " Total: " << total << endl;
    }

    cout << total << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}