#include "rotating_point.h"
#include "complex.c"
#include <stdio.h>

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX Chasil = C;
    int i;
    for (i = 1; i < p; i++) {
        Chasil = MultiplyCOMPLEX(Chasil,C);
    }
    return Chasil;
};

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    COMPLEX pC = C;
    int i =0;
    float x,y;
    while (i < n && x*x+y*y <= 1) {
        x = Absis(*P);
        y = Ordinat(*P);
        pC = PowerCOMPLEX(pC,i);
        Absis(*P) = x * Real(pC) - y*Imag(pC);
        Ordinat(*P) = x * Real(pC) - y*Imag(pC);
        i++;
    }
    if (x*x+y*y > 1) {
        printf("Titik keluar dari lingkaran pada iterasi ke %d",i+1);
    } else {
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi",i);
    }
    
};

int main() {
    POINT P = {0.5,0.5};
    COMPLEX C = {1.0,0.5};
    int n = 2;
    TransformPointByComplexPower(&P,C,n);
}

