#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    double ncows, ncars, nshow;

    if (!(cin >> ncows)) return false;

    cin >> ncars >> nshow;

    double prob_elegir_vaca = ncows / (ncars + ncows);
    double prob_cambiar_vaca_coche = ncars / (ncars + ncows - nshow - 1); // Descartamos nuestra puerta
    double prob_elegir_coche = ncars / (ncars + ncows);
    double prob_cambiar_coche_coche = (ncars - 1)/ (ncars + ncows - nshow - 1); // Descartamos nuestra puerta (que tenía un coche, por lo que 1 menos)



    printf("%.5f\n", (prob_elegir_vaca * prob_cambiar_vaca_coche) + (prob_elegir_coche * prob_cambiar_coche_coche));

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve()) {
    }
  
    return 0;
}