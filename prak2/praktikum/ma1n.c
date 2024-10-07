# include "liststatik.h"
#include <stdio.h>

int main(){
    ListStatik l, setL;
    int i, j, count, maxCount, secndMaxCount;
    ElType result;
    maxCount = secndMaxCount = 0;
    readList(&l);
    setL = createSet(l);
    // Find max count
    for (i = 0; i < listLength(setL); i++){
        count = countVal(l,setL.contents[i]);
        if ( count > maxCount){maxCount = count; }
    }
    sortList(&setL,true);
    for (i = 0; i < listLength(setL); i++){
        count = countVal(l,setL.contents[i]);
        if ( count > secndMaxCount && count != maxCount){
            secndMaxCount = count;
            result = setL.contents[i]; }
    }

    if (secndMaxCount == 0) {printf("Tidak ada elemen kedua yang paling sering muncul\n");} 
    else {printf("%d\n",result);}

    return 0;
}
