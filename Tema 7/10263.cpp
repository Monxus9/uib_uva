#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double xm, ym;
double xA, yA, xB, yB;
int n;

double min_dist;
double xmin, ymin;


bool estaDentro(double xaux, double yaux) {
    if ((xA >= xaux && xB <= xaux)||(xB >= xaux && xA <= xaux)) {
        //cout << "SI1 " << xA << " " << xaux << " " << xB << " " << endl;
        if ((yA >= yaux && yB <= yaux)||(yB >= yaux && yA <= yaux)) {
            //cout << "SI2 " << yA << " " << yaux << " " << yB << " " << endl;
            return true;
        }
    }
    return false;
}

void calcDist() {
    
    // Pendiente
    double pendX = xB-xA;
    double pendY = yB-yA;
    double m = (pendY/pendX);

    // Comprobar rectas paralelas a los ejes
    if (pendX == 0) {
        //cout << "PX0" << endl;
        // Punto en la misma recta
        if (xm == xA) {
            if (estaDentro(xm, ym)) {
                min_dist = 0;
                xmin = xm;
                ymin = ym;
                return;
            } else {
                double distA =sqrt((xm-xA)*(xm-xA) + (ym-yA)*(ym-yA));
                double distB =sqrt((xm-xB)*(xm-xB) + (ym-yB)*(ym-yB));

                if (distA < distB) {
                    if (distA < min_dist) {
                        xmin = xA;
                        ymin = yA;
                        min_dist = distA;
                    }
                } else {
                    if (distB < min_dist) {
                        xmin = xB;
                        ymin = yB;
                        min_dist = distB;
                    }
                }
            }
            return;
        }
        if ((yA >= ym && yB <= ym)||(yB >= ym && yA <= ym)) {
            // Punto corte
            double xCorte = xA;
            double yCorte = ym;

            double dist = abs(xm-xA);
            if (dist < min_dist) {
                xmin = xCorte;
                ymin = yCorte;
                min_dist = dist;
            }
        }

        double distA =sqrt((xm-xA)*(xm-xA) + (ym-yA)*(ym-yA));
        double distB =sqrt((xm-xB)*(xm-xB) + (ym-yB)*(ym-yB));

        if (distA < distB) {
            if (distA < min_dist) {
                xmin = xA;
                ymin = yA;
                min_dist = distA;
            }
        } else {
            if (distB < min_dist) {
                xmin = xB;
                ymin = yB;
                min_dist = distB;
            }
        }
        
        return;
    }

    if (pendY == 0) {
        //cout << "PY0" << endl;
        // Punto en la misma recta
        if (ym == yA) {
            if (estaDentro(xm, ym)) {
                min_dist = 0;
                xmin = xm;
                ymin = ym;
                return;
            } else {
                double distA =sqrt((xm-xA)*(xm-xA) + (ym-yA)*(ym-yA));
                double distB =sqrt((xm-xB)*(xm-xB) + (ym-yB)*(ym-yB));

                if (distA < distB) {
                    if (distA < min_dist) {
                        xmin = xA;
                        ymin = yA;
                        min_dist = distA;
                    }
                } else {
                    if (distB < min_dist) {
                        xmin = xB;
                        ymin = yB;
                        min_dist = distB;
                    }
                }
            }
            return;
        }
        if ((xA >= xm && xB <= xm)||(xB >= xm && xA <= xm)) {
            // Punto corte
            double xCorte = xm;
            double yCorte = yA;

            double dist = abs(ym-yA);
            if (dist < min_dist) {
                xmin = xCorte;
                ymin = yCorte;
                min_dist = dist;
            }

        }

        double distA =sqrt((xm-xA)*(xm-xA) + (ym-yA)*(ym-yA));
        double distB =sqrt((xm-xB)*(xm-xB) + (ym-yB)*(ym-yB));

        if (distA < distB) {
            if (distA < min_dist) {
                xmin = xA;
                ymin = yA;
                min_dist = distA;
            }
        } else {
            if (distB < min_dist) {
                xmin = xB;
                ymin = yB;
                min_dist = distB;
            }
        }
        
        return;
    }

    // Punto corte
    double corte = yA-m*xA;

    // Comprobar si el punto M esta en la recta
    if (ym == m * xm + corte) {
        //cout << "INLINE" << endl;
        // Ver si está dentro o fuera
        if (estaDentro(xm, ym)) {
            min_dist = 0;
            xmin = xm;
            ymin = ym;
            return;
        }

        double distA =sqrt((xm-xA)*(xm-xA) + (ym-yA)*(ym-yA));
        double distB =sqrt((xm-xB)*(xm-xB) + (ym-yB)*(ym-yB));

        if (distA < distB) {
            if (distA < min_dist) {
                xmin = xA;
                ymin = yA;
                min_dist = distA;
            }
        } else {
            if (distB < min_dist) {
                xmin = xB;
                ymin = yB;
                min_dist = distB;
            }
        }
        return;
    }

    // Recta 2
    double m2 = -1 / m;
    double corte2 = ym-m2*xm;

    // Punto corte rectas
    double xCorte = (corte2-corte)/(m-m2);
    double yCorte = m2 * xCorte + corte2;

    // Distancia
    if (estaDentro(xCorte, yCorte)) {
        //cout << "DENTRO " << xCorte << " " << yCorte << endl;
        double dist = sqrt((xm-xCorte)*(xm-xCorte) + (ym-yCorte)*(ym-yCorte));
        if (dist < min_dist) {
            xmin = xCorte;
            ymin = yCorte;
            min_dist = dist;
        }
    } else {
        //cout << "FUERA " << xCorte << " " << yCorte << endl;
        double distA =sqrt((xm-xA)*(xm-xA) + (ym-yA)*(ym-yA));
        double distB =sqrt((xm-xB)*(xm-xB) + (ym-yB)*(ym-yB));

        if (distA < distB) {
            if (distA < min_dist) {
                xmin = xA;
                ymin = yA;
                min_dist = distA;
            }
        } else {
            if (distB < min_dist) {
                xmin = xB;
                ymin = yB;
                min_dist = distB;
            }
        }
    }
    
}

bool solve() {
    

    if (!(cin >> xm)) return false;



    cin >> ym >> n;
    
    if (n == 0) {
        cin >> xA >> yA;
        printf("%.4f\n", xA);
        printf("%.4f\n", yA);
        return true;
    }
    
    
    cin >> xA >> yA >> xB >> yB;

    min_dist = 999999;

    calcDist();

    for (size_t i = 1; i < n; i++)
    {
        xA = xB;
        yA = yB;
        cin >> xB >> yB;
        calcDist();
    }

    printf("%.4f\n", xmin);
    printf("%.4f\n", ymin);
    

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}