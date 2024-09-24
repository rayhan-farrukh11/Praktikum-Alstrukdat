# include "complex.h"
# include <stdio.h>

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
boolean IsCOMPLEXValid(float Re, float Im) {
    return (!(Re == INFINITY || Re == -INFINITY || Re != Re || Re == 0xdeadbeef)
            && !(Im == INFINITY || Im == -INFINITY || Im != Im|| Im == 0xdeadbeef)) ? true : false;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

/* KELOMPOK BACA/TULIS                                               */
void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;
    scanf("%f %f", &Re,&Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) > 0) {
    printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
    else {
        printf("%.2f-%.2fi\n", Real(C), Imag(C) * (-1));
        }
    }

/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Chasil;
    CreateComplex(&Chasil, Real(C1) + Real(C2), Imag(C1) + Imag(C2));
    return Chasil;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Chasil;
    CreateComplex(&Chasil, Real(C1) - Real(C2), Imag(C1) - Imag(C2));
    return Chasil;
}

/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Chasil;
    CreateComplex(&Chasil, Real(C1)*Real(C2) - Imag(C1)*Imag(C2), Real(C1)*Imag(C2) + Imag(C1)*Real(C2));
    return Chasil;
}

/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Chasil;
    float denominator = Real(C2)*Real(C2) + Imag(C2)*Imag(C2);
    if ( denominator == 0) {
        CreateComplex(&Chasil, 0,0);
        return Chasil;
    }
    float numeratorReal = Real(C1) * Real(C2) + Imag(C1) * Imag(C2);
    float numeratorImag = Imag(C1) * Real(C2) - Real(C1) * Imag(C2);
    CreateComplex(&Chasil, numeratorReal / denominator, numeratorImag / denominator);
    return Chasil;
}

/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */
float AbsCOMPLEX(COMPLEX C) {
    return sqrtf(Real(C)*Real(C) + Imag(C)*Imag(C));
}

/* Rumus: Conj(C) = Re - i*Im */
COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    COMPLEX hasil;
    CreateComplex(&hasil, Real(C), Imag(C)*-1);
    return hasil;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2) && Imag(C1) == Imag(C2)) ? true : false; 
}


boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) != Real(C2) || Imag(C1) != Imag(C2)) ? true : false;
}

