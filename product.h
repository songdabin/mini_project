#ifndef PRODUCT
#define PRODUCT
typedef struct{
    char name[20]; // 제품명
    int weight; // 제품중량
    int price; // 판매가격
    int star; // 별점
    int star_cnt; // 별점개수
} Product;
int createProduct(Product *p); // 제품 추가 함수
int readProduct(Product p); // 하나의 제품 출력 함수
int updateProduct(Product *p); // 제품 정보 업데이트
int updateStar(Product *p); // 별점 정보 업데이트
int deleteProduct(Product *p); // 제품 정보 삭제
void saveFile(Product *p, int count); // 제품 정보 파일에 저장
void getFile(Product *p); // 제품 정보 파일에서 불러오기
void searchProduct(Product *p, int count); // 제품이름 검색
void searchPrice(Product *p, int count); // 제품가격 검색
void searchStar(Product *p, int count); // 제품별점 검색
#endif
