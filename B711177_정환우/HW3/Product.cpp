
#include "Product.h"

// Function : getProductDetail
// Description: 상품 상세 정보를 출력하는 함수.
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getProductDetail() {
    cout << this->name << " " << this->companyName << " " << this->price << " " << this->stockCount << endl;
}

// Function : getSoldOutProductDetail
// Description: 판매 완료된 상품 조회 하는 함수
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getSoldOutProductDetail() {
    // stockCount 가 0이 아니면 판매 완료된 상품이 아니다.

    if (this->stockCount != 0){
        return;
    }

    cout << this->name << " " << this->companyName << " " << this -> price << " " << this->count << " " << this->score << endl;
}

// Function : getProductStat
// Description: 판매 상품 통계 출력하는 함수.
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getProductStat() {
    int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
    int totalPrice = this->price * sellCount;
    int averageScore = this->score / sellCount; // 평균 구매만족도 = 총 만족도 / 판매 수량
    cout << this->name << " " << totalPrice << " " << averageScore << endl;
}