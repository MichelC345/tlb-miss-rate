//Michel 10/10/2023
//Beecrowd - 1768
//Linguagem C++
//Código modificado e adaptado para gerar os traces

#include <iostream>
#include <cstring>
using namespace std;

void imprimir(char str[], int n) {
    int j = 0;
    while (j < n && str[j] != '*') {
        cout << str[j];
        j++;
    }
    while (j < n && str[j] == '*') {
        cout << str[j];
        j++;
    }
    puts("");
}

int main() {
    const int n = 15;

    //while (scanf("%d", &n) != EOF) {
        char str[n+1], b1[n+1], b2[n+1];
        int mid = n/2;
        memset(str, ' ', sizeof(char) * (n+1));
        str[mid] = '*';
        str[n] = '\0';
        int c1 = mid-1, c2 = mid+1;
        strcpy(b1, str);
        //cout << str << endl;
        imprimir(str, n);

        str[c1] = '*';
        str[c2] = '*';
        strcpy(b2, str);
        //cout << str << endl;
        //imprimir(str, n);
        c1--;
        c2++;

        for (int i = 3;i <= n;i += 2) {
            //cout << str << endl;
            imprimir(str, n);
            if (c1 >= 0) {
                str[c1] = '*';
                c1--;
            }
            if (c2 < n) {
                str[c2] = '*';
                c2++;
            }
        }
        imprimir(b1, n);
        imprimir(b2, n);
        //cout << b1 << endl << b2 << endl;
        puts("");
    //}

    return 0;
}