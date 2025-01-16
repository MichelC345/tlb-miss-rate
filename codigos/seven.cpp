//Michel 17/11/2023
//Beecrowd - 2590
//Linguagem C++
//Código modificado e adaptado para gerar os traces

#include <iostream>
using namespace std;

int main () {
    const int t = 50;
    int num[t], n;
    for (int i = 0;i < t;i++) {
        num[i] = rand();
    }
    int v[4] = {1, 7, 9, 3};
    for (int i = 0;i < t;i++) {
        //scanf ("%d", &n);
        n = num[i];
        printf("%d\n", v[n % 4]);
        //printf ("%d\n", v[n & 3]);
    }

    return 0;
}