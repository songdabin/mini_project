#include <stdio.h>
#include <string.h>
#include "product.h"

int createProduct(Product *p){
        printf("제품명은? ");
        scanf("%s", p->name);
        printf("제품중량은? ");
        scanf("%d", &p->weight);
        printf("판매가격은? ");
        scanf("%d", &p->price);
        printf("별점은? ");
        scanf("%d", &p->star);
        p->star_cnt=0;
        p->star_cnt++;
        return 1;
}
int readProduct(Product p){
        printf("제품명 : %s\n", p.name);
        printf("제품중량 : %d\n", p.weight);
        printf("판매가격 : %d\n", p.price);
        printf("별점 : %d\n", p.star);
        printf("별점개수 : %d\n", p.star_cnt);
        return 1;
}
int updateProduct(Product *p){
        printf("제품명은? ");
        scanf("%s", p->name);
        printf("제품중량은? ");
        scanf("%d", &p->weight);
        printf("판매가격은? ");
        scanf("%d", &p->price);
        printf("별점은? ");
        scanf("%d", &p->star);
        return 1;
}
int updateStar(Product *p){
        int temp;
        printf("별점은? ");
        scanf("%d", &temp);
        p->star*=p->star_cnt;
        p->star+=temp;
        
        p->star_cnt++;
        p->star/=p->star_cnt;
        return 1;
}
int deleteProduct(Product *p){
        p->price=-1;
        p->star=-1;
        p->star_cnt=-1;
        return 1;
}
void saveFile(Product *p, int count){
        FILE *f;
        f=fopen("product.txt", "wt");
        for (int i=0; i<count; i++) {
                if (p[i].price==-1) continue;
                fprintf("%s %d %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].star, p[i].star_cnt);
        }
        printf("저장됨!\n");
        fclose(f);
}
void getFile(Product *p){
        int count=0, i=0;
        FILE *f;
        f=fopen("product.txt", "rt");
        if (f==NULL) printf("=> 파일 없음\n");
        else {
                for (; i<20; i++) {
                        fscanf(f, "%s", p[i].name);
                        if (feof(f)) break;
                        fscanf(f, "%d", &p[i].weight);
                        fscanf(f, "%d", &p[i].price);
                        fscanf(f, "%d", &p[i].star);
                        fscanf(f, "%d", &p[i].star_cnt);
                }
                printf("=> 로딩 성공!\n");
        }
        fclose(f);
}
