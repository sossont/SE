//
//  ProductCollection.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "ProductCollection.hpp"

void ProductCollection::getProductStat() {
    for (auto product : ownedProduct) {
        product.getProductStat();
    }
}

// 모든 상품 순회해서 조회하면 된다.
void ProductCollection::getAllProduct() {
    for (auto product : ownedProduct) {
        product.getProductDetail();
    }
}


void ProductCollection::getSoldOutProduct() {
    for (auto product : ownedProduct) {
        product.getSoldOutProductDetail();
    }
}

// 상품 정보 추가
void ProductCollection::addNewProduct(string sellerName, string productName, string companyName, int price, int count) {
    Product product = *new Product(sellerName, productName, companyName, productNum, price, count);
    // 전역 배열에 추가
    product.getProductDetail();
    productList[productNum++] = product;
    this->ownedProduct.push_back(product);
}
