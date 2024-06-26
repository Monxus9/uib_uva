#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589793

bool solve() {
    double ax, ay, bx, by, cx, cy;

    if (!(cin >> ax)) return false;

    cin >> ay >> bx >> by >> cx >> cy;

    // Pag 130
    double ab = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
    double ac = sqrt((ax-cx)*(ax-cx) + (ay-cy)*(ay-cy));
    double bc = sqrt((bx-cx)*(bx-cx) + (by-cy)*(by-cy));

    // Pag 128
    double s = (ab + ac + bc) / 2;
    double area = sqrt(s*(s - ab)*(s - ac)*(s - bc));
    

    double radio = ab * ac * bc / (4 * area);

    printf("%.2f\n", 2* PI * radio); 

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}