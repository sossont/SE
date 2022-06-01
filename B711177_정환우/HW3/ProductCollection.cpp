//
// Created by 정환우 on 2022/06/01.
//

#include "ProductCollection.h"

// Function : getProductStat
// Description: 컬렉션 순회 돌면서, 판매 통계 출력 한다.
// Created: 2022/5/31 18:00
// Author: 정환우

void ProductCollection::getProductStat() {
    for (auto product : ownedProduct) {
        product.getProductStat();
    }
}

// Function : getAllProduct
// Description: 등록 상품 조회하는 함수로, 컬렉션 순회를 돌면서 상품 정보 출력한다.
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getAllProduct() {
    for (auto product : ownedProduct) {
        product.getProductDetail();
    }
}

// Function : getSoldOutProduct
// Description: 컬렉션 순회 돌며 판매 완료된 상품 상세 정보 출력
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getSoldOutProduct() {
    for (auto product : ownedProduct) {
        product.getSoldOutProductDetail();
    }
}

// Function : addNewProduct
// Description: 새로운 상품 추가하는 함수로, 새로운 상품 생성후 컬렉션에 추가한다.
// Created: 2022/5/31 18:00
// Author: 정환우

void ProductCollection::addNewProduct(string productName, string companyName, int price, int count) {
    Product product = *new Product(productName, companyName, productNum, price, count);
    productList[productNum] = product;
    // 상품 추가했으므로 상품 Id 1 증가
    productNum += 1;
    ownedProduct.push_back(product);
}