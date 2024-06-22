#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(bool zzz) {
    int num;
    cin >> num;
    if (num == 0)
        return false;
    else {
        if (zzz) printf("\n");
        // Code solve
        int sols = 0;
        int n1, n2;
        int limit = (99999 / num)+1;
        bool valid;
        for (int i = 1234; i <= limit ; i++)
        {
            if (i == 13458) {
                int a = 1;
            }
            int aux = i * num;
            valid = true;
            bool nums[10] = {1,1,1,1,1,1,1,1,1,1};
            if (i < 10000) {
                if (aux < 10000) continue;
                nums[0] = false;
            }
            int aux2 = i;
            while (aux2 > 0) {
                if (nums[aux2 % 10]) {
                    nums[aux2 % 10] = false;
                } else {
                    valid = false;
                }
                aux2 /= 10;
            }
            if (!valid) continue;
            while (aux > 0) {
                if (nums[aux % 10]) {
                    nums[aux % 10] = false;
                } else {
                    valid = false;
                }
                aux /= 10;
            }
            if (!valid) continue;
            printf("%05d / %05d = %d\n", i * num, i, num);
            sols++;
        }


        if (sols == 0) {
            printf("There are no solutions for %d.\n", num);
            //cout << "There are no solutions for " << num << "." << endl;
        }
        //printf("\n");
        //cout << endl;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(false);
    while(solve(true)) {

    }
  
    return 0;
}