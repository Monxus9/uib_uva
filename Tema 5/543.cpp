#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 1000000
bool primos[N] = {0};

void criba() {
    memset(primos,1,N * sizeof(*primos));
    for (size_t i = 2; i*i <= N; i++)
    {
        if (primos[i]) {
            for (size_t j = i*i; j <= N; j+=i)
            {
                primos[j] = false;
            }
        }
    }
}


bool solve() {
    int num;
    cin >> num;
    if (num == 0)
        return false;
    else {
        // Code solve
        int a;
        a = 3;
        for (; a <=num/2; a++)
        {
            if (!primos[a]) continue;
            if (!primos[num-a]) continue;
            printf("%d = %d + %d\n",num,a,num-a );
            return true;
            
        }
        printf("Goldbach's conjecture is wrong.\n");

    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    criba();

    while(solve()) {
    }
  
    return 0;
}