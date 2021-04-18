#include <stdio.h>
#include "manager.h"

void listProduct(Product *p, int count) {
    printf("\n-----제품정보-----\n");
    for (int i=0; i<count; i++) {
        if (p[i].weight<=0||p[i].price<=0) continue;
        printf("Product No.%d\n", i+1);
        readProduct(p[i]);
        printf("\n");
    }
}

int selectNum(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("상품 번호는? ");
    scanf("%d", &no);
    return no;
}
