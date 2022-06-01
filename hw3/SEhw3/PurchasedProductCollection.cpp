//
//  PurchasedProductCollection.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "PurchasedProductCollection.hpp"

//생성자
//구매한 물건 개수 0으로 초기화
PurchasedProductCollection::PurchasedProductCollection(){
    this-> PurchasedCount =0;
}

//새롭게 구매한 물건 추가
void PurchasedProductCollection::addNewProduct(int productId){
    this -> PurchasedList[this -> PurchasedCount].setProductId(productId);
    this ->PurchasedCount = this -> PurchasedCount + 1 ;
}

void PurchasedProductCollection::addProductScore(int productId ,int score){
    // 한 유저의 구매 목록들 중, productId가 일치하는 PurchasedProduct 에 score 값을 넣어준다.
    for(int j =0; j < this ->PurchasedCount; j++){
        if( this -> PurchasedList[j].getProductId() == productId){
            PurchasedList[j].setScore(score);
        }
    }
    
    
}

int PurchasedProductCollection::getPurchasedCount(){
    return this ->PurchasedCount;
}
