#include <iostream>
#include <bits/stdc++.h>
using namespace std;



bool solve() {
    int size;
    if (cin >> size) {
        int libros[size];

        for (size_t i = 0; i < size; i++)
        {
            cin >> libros[i];
        }
        int obj;
        cin >> obj;
        
        sort(libros, libros+size);

        // Busqueda
        int left = 0;
        int right = size-1;

        int libro1, libro2;

        while (left < right) {
            if (libros[left] + libros[right] > obj) {
                right--;
            } else if (libros[left] + libros[right] < obj) {
                left++;
            } else {
                libro1 = left++;
                libro2 = right--;
            }
        }
        
        printf("Peter should buy books whose prices are %d and %d.\n\n", libros[libro1], libros[libro2]);

        return true;
    }
    return false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}