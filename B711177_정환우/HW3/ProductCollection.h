#include <vector>
#include "Product.h"
// Class : ProductCollection
// Description : 판매자가 판매한 상품들을 저장해놓는 컬렉션
// Created : 2022/5/31 18:00
// Author : 정환우
using namespace std;

class ProductCollection
{
private:
    vector<Product> ownedProduct;

public:
    void addNewProduct(string productName, string companyName, int price, int count); // 3.1 판매 상품 등록. 상품명, 제작회사명, 가격, 수량
    void getAllProduct();                                                             // 3.2 등록 상품 조회. 모든 ownedProduct 순회하면서 상품명, 제작회사명, 가격, 수량 출력하면 된다.
    void getSoldOutProduct();                                                         // 3.3 판매 완료 상품 조회
    void getProductStat();                                                            // 5.1 판매 상품 통계 출력하는 함수.
};