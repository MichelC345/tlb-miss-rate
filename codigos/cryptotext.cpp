//Michel 28/04/2024
//Beecrowd - 2866
//Linguagem C++
//Código modificado e adaptado para gerar os traces

#include <iostream>
#include <cstring>
using namespace std;

//const int c = 25;
const char* entry[] = { "lPDrQLGiSVVUg",
"TyltnAePKrruEcQRYKL",
"UVOOnoFFQiUtcuGHLrtLVGQsEnocE",
"VsHyoDMtVL",
"derKetYXsTQXPPiBgerT",
"rGCMLUWRaelPCYcH",
"flAoGg",
"eMJTviAecWAeVHGr",
"niamodIU",
"sdoUVZhVGHHDPZtKem",
"retZpaFPhcYYKFL",
"sAeIkaGImDOX",
"nUoGEitceWJZOtorpC",
"XZLTseiciKloLOWpK",
"FnONaolF",
"EeTdiVHKPQwX",
"ytuEaReJbEE",
"rQNeCgUQJaLnMaCBRmIB",
"aidUniNKXK",
"noitiRsopYY",
"QDTCWnekSaQtTRDO",
"tEFYrEos",
"sgnIiAtsDMYNilSB",
"sledoPmM",
"lOeahcWOOiHmIZ",
};

#define c (sizeof (entry) / sizeof (const char *))

int main() {
    int tam, i;
    char e[100], r[100];
    //printf ("c %d\n", c);

    for (int index = 0;index < c;index++) {
        //scanf(" %s", e);
        printf("%s\n", entry[index]);
        strcpy(e, entry[index]);
        tam = strlen(e);
        i = 0;
        for (int j = tam-1;j >= 0;j--) {
            if (e[j] > 96 && e[j] < 123) {
                r[i++] = e[j];
            }
        }
        r[i] = '\0';
        printf("%s\n", r);
    }

    return 0;
}