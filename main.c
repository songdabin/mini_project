#include <stdio.h>
#ifndef PRODUCT
#include "product.h"
#endif
#ifndef MANAGER
#include "manager.h"
#endif

int selectMenu(){
        int menu;
        printf("\n-----MINI PROJECT-----\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 별점\n");
	printf("5. 제품 이름 검색\n");
        printf("6. 제품 가격 검색\n");
        printf("7. 제품 별점 검색\n");
	printf("8. 삭제\n");
        printf("9. 파일 저장\n");
        printf("10. 파일 불러오기\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
        scanf("%d", &menu);
        return menu;
}

int main(){
        Product p[100];
        int index=0, count=0;

        while(1){    
                int menu=selectMenu();
                if (menu==0) break;
                if (menu==1||menu==3||menu==4){
                        if (count==0) continue;
                }
                if (menu==1){
                        if (count>0) listProduct(p, index);
                }
                else if (menu==2){
                        printf("\n-----제품등록-----\n");
                        count+=createProduct(&p[index++]);
                }   
                else if (menu==3){
                        int no=selectNum(p, index);
                        if (no==0){
                                printf("취소됨!\n");
                                continue;
                        }
                        printf("\n-----제품업데이트-----\n");
                        updateProduct(&p[no-1]);
                }
                else if (menu==4){
                        int no=selectNum(p, index);
                        if (no==0){
                                printf("취소됨!\n");
                                continue;
                        }
                        printf("\n-----별점추가-----\n");
                        updateStar(&p[no-1]);
                }
	       else if (menu==5){
                        searchProduct(p, index);
                }
                else if (menu==6){
                        searchPrice(p, index);
                }
                else if (menu==7){
                        searchStar(p, index);
                }
                else if (menu==8){
                        int no=selectNum(p, index);
                        if (no==0){
                                printf("취소됨!\n");
                                continue;
                        }
                        int deleteok;
                        printf("정말 삭제하시겠습니까?(삭제 : 1) ");
                        scanf("%d", &deleteok);
                        if (deleteok==1) {
                                printf("\n-----제품삭제-----\n");
                                int isDel=deleteProduct(&p[no-1]);
                                if (isDel==1) {
                                        printf("=> 삭제됨!\n");	
                                        index--;
                                }
                        }
                }
        }
        return 0;
}
