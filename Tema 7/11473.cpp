#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int k, trees;
vector<double> dist_acc;
vector<double> coorX;
vector<double> coorY;

int num_caso;


double calcDist(int i) {
    return sqrt((coorX[i] - coorX[i-1])*(coorX[i] - coorX[i-1]) + (coorY[i] - coorY[i-1])*(coorY[i] - coorY[i-1]));
}

void solve() {
    cin >> k >> trees;

    dist_acc.resize(k);
    coorX.resize(k);
    coorY.resize(k);

    // Recorrer árboles
    double treeX, treeY;

    cin >> treeX >> treeY;
    coorX[0] = treeX;
    coorY[0] = treeY;
    dist_acc[0] = 0.0;

    double total_dist = 0.0;

    for (int i = 1; i < k; i++)
    {
        cin >> treeX >> treeY;
        coorX[i] = treeX;
        coorY[i] = treeY;
        total_dist += calcDist(i);
        dist_acc[i] = total_dist;

    }

    printf("Road #%d:\n", num_caso);
    printf("%.2f %.2f\n", coorX[0], coorY[0]);

    double dist_arboles = total_dist / (trees-1);

    int next_coor = 1;
    double next_dist = dist_arboles;

    for (int i = 1; i < trees-1; i++)
    {
        ////cout << "Next d" << next_dist << endl;
        while (dist_acc[next_coor] < next_dist) {
            next_coor++;
            ////cout << "Dist acc " << dist_acc[next_coor] << endl;
        }
        ////cout << next_coor << endl;

        double dist_puntos = dist_acc[next_coor] -dist_acc[next_coor-1];
        double dist_recorrer = next_dist - dist_acc[next_coor-1];
        ////cout << dist_puntos << endl;
        ////cout << dist_recorrer << endl;
        // printf("%.2f %.2f\n", x_find, y_find);

        double perc = dist_recorrer / dist_puntos;
        ////cout << perc << endl;

        double x_find = (1-perc)*coorX[next_coor-1] + perc*coorX[next_coor];
        double y_find = (1-perc)*coorY[next_coor-1] + perc*coorY[next_coor];
        printf("%.2f %.2f\n", x_find, y_find);

        next_dist += dist_arboles;
    }
    


    printf("%.2f %.2f\n\n", coorX[k-1], coorY[k-1]);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    num_caso = 1;
    while(casos--) {
        solve();
        num_caso++;
    }
  
    return 0;
}