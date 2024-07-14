#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

// Sacado del libro de PC, vol 1, pag 125
class FenwickTree{
    public:
        vector<int> ft;

        FenwickTree(int m){
            ft.assign(m+1, 0);
        }

        int rsq(int j){
            int sum = 0;
            for(; j; j -= LSOne(j))
                sum += ft[j];
            return sum;
        }

        int rsq(int i, int j){
            return rsq(j) - rsq(i-1);
        }
        void update(int i, int v){
            for(; i < ft.size(); i += LSOne(i))
                ft[i] += v;
        }
};





int busquedaBinaria(FenwickTree arbol, long long num, int left, int right) {
    //cout << "BUSCA " << num << endl;
    //cout << "L: " << left << " R: " << endl;
    int mid;
    while (right-left > 1){
        mid = (right+left) / 2;
        //cout << "MID: " << mid << endl;
        if  (arbol.rsq(mid) < num){
            left = mid;
        } else {
            right = mid;
        }
        //cout << "L: " << left << " R: " << endl;
    }
    return right;
}

bool solve() {
    int size;
    cin >> size;
    if (size == 0) return false;

    FenwickTree arbol = FenwickTree(size);
    
    // Leer sinfonias (llenar 0 para los indices)
    int sinfonias[size] = {0};
    
    for (int i = 0; i < size; i++)
    {
        cin >> sinfonias[i];
    }

    long long first_idx = 0;
    long long last_idx = 0;
    int idx_aux = 0;

    int n_consultas;
    cin >> n_consultas;

    long long num;
    for (int i = 0; i < n_consultas; i++)
    {
        cin >> num;
        // Si todavia no lo hemos añadido
        while (num > last_idx) {
            // Ver espacios necesarios
            long long espacio_adicional = arbol.rsq(sinfonias[idx_aux], size);

            // Actualizar indices
            last_idx++;
            first_idx = last_idx;
            last_idx += espacio_adicional;

            // Actualizamos sinfonia procesada
            arbol.update(sinfonias[idx_aux], 1);
            idx_aux++;

            // cout << first_idx << " " << last_idx << endl;

        }

        // Busqueda en el árbol
        // OJO desplazamiento indice
        //cout << num << ": " << arbol.rsq(sinfonias[idx_aux-1]) + num - first_idx << endl;
        //cout << num-first_idx << endl;
        int num_simfonia = (num-first_idx == 0) ? sinfonias[idx_aux-1] : busquedaBinaria(arbol, arbol.rsq(sinfonias[idx_aux-1]) + num - first_idx, 1, size);
        // Comprobar si está colocada o no
        bool colocada = arbol.rsq(num_simfonia) == num_simfonia;
        //cout << num_simfonia << endl;

        if (colocada) {
            printf("Es la %d\n", num_simfonia);
        } else {
            printf("Fue la %d\n", num_simfonia);
        }

    }
    printf("---\n");
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {}
  
    return 0;
}