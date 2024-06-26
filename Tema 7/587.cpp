#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int caso;

bool solve() {
    string line;
    getline(cin, line);
    if (line == "END") return false;

    int idx = 0;
    char c = line[idx++];

    double x = 0.0, y = 0.0;

    while (c != '.') {
        double num = 0;
        string dir = "";

        while (c >= '0' && c <= '9') {
            num *= 10;
            num += c - '0';
            c = line[idx++];
        }
        while (c != '.' && c != ',') {
            dir += c;
            c = line[idx++];
        }

        if (dir == "N") {
            y += num;
        }
        if (dir == "S") {
            y -= num;
        }
        if (dir == "W") {
            x -= num;
        }
        if (dir == "E") {
            x += num;
        }
        if (dir == "NE") {
            double aux = num / sqrt(2);
            x += aux;
            y += aux;
            
        }
        if (dir == "SE") {
            double aux = num / sqrt(2);
            x += aux;
            y -= aux;
        }
        if (dir == "SW") {
            double aux = num / sqrt(2);
            x -= aux;
            y -= aux;
        }
        if (dir == "NW") {
            double aux = num / sqrt(2);
            x -= aux;
            y += aux;
        }

        if (c == ',') c = line[idx++];

    }

    double dist = sqrt(x*x + y*y);

    printf("Map #%d\n", caso++);
    printf("The treasure is located at (%.3f,%.3f).\n", x, y);
    printf("The distance to the treasure is %.3f.\n\n", dist);

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    caso = 1;
    while(solve()) {
    }
  
    return 0;
}