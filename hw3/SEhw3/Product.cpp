//
//  Product.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/01.
//

#include "Product.hpp"


void Product::getProductStat() {
    int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
    int totalPrice = this->price * sellCount;
    int averageScore = this->score / sellCount; // 평균 구매만족도 = 총 만족도 / 판매 수량
    cout << this->name << " " << totalPrice << " " << averageScore << endl;
}
//Function
//Descrpition: 상품의 정보를 출력해준다.
void Product::getProductDetail() {
    cout << this->name << " " << this->companyName << " " << this->price << " " << this->stockCount << endl;
}

void Product::getSoldOutProductDetail() {
    // stockCount 가 0이 아니면 판매 완료된 상품이 아니다.

    if (this->stockCount != 0){
        return;
    }

    cout << this->name << " " << this->companyName << " " << this -> price << " " << this->count << " " << this->score << endl;
}

void Product::addScore(int score){
    this -> score += score;
}

void Product::changeProductAmount(){
    this -> stockCount = this->stockCount -1;
}
