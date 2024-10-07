# include "liststatik.h"
#include <stdio.h>

ListStatik createSet(ListStatik l){
    ListStatik set;
    boolean duplicate;
    int i,j;
    CreateListStatik(&set);
    for (i=0;i < listLength(l); i++){
    duplicate = false;
    for (j = 0; j < listLength(set);j++){
        if (l.contents[i] == set.contents[j]){duplicate = true;}}
    if (!duplicate) {
        insertLast(&set,l.contents[i]);
    }
}
    return set;
}

int countVal(ListStatik l, ElType val) {
      int i;
      int count = 0;
      for (i=0;i<listLength(l);i++){
            if (l.contents[i] == val) count++;
      }
      return count;
};

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
