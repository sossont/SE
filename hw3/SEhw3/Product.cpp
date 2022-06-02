//
//  Product.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/01.
//

#include "Product.hpp"


Product::Product(string sellerName, string productName, string companyName, int productId, int price, int count) {
    this->sellerName = sellerName;
    this->productId = productId;
    this->productName = productName;
    this->companyName = companyName;
    this->price = price;
    this->count = count;
    this->stockCount = count;
}

void Product::getProductDetail() {
    fprintf(out_fp, "%s %s %d %d\n\n", this->name.c_str(), this->companyName.c_str(), this->price, this->stockCount);
}

void Product::getProductStat() {
    int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
    int totalPrice = this->price * sellCount;
    int averageScore = this->score / sellCount; // 평균 구매만족도 = 총 만족도 / 판매 수량
    
}

//Function
//Descrpition: 상품의 정보를 출력해준다.
void Product::getSoldOutProductDetail() {
    // stockCount 가 0이 아니면 판매 완료된 상품이 아니다.

    if (this->stockCount != 0){
        return;
    }

    //cout << this->name << " " << this->companyName << " " << this -> price << " " << this->count << " " << this->score << endl;
}

void Product::addScore(int score){
    this -> score += score;
}

void Product::changeProductAmount(){
    this -> stockCount = this->stockCount -1;
}
