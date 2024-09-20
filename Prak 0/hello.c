#include <stdio.h>
#include <stdlib.h>

int main() {
    int tinggi;
    scanf("%d",&tinggi);
    for (int i = 0; i < tinggi; i++) {
        for (int j ; j < i; j++) {
            printf("*");
        }
        printf("");
    }
    return 0;
}