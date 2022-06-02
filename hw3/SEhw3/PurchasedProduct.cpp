//
//  PurchasedProduct.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "PurchasedProduct.hpp"

PurchasedProduct::PurchasedProduct(int id){
    this->productId = id;
    score = -1;
}

bool PurchasedProduct::isRate(){
    if(this->score == -1){
        return false;
    }
    else
        return true;
}

void PurchasedProduct::setProductId(int productId){
    this -> productId = productId;
}

void PurchasedProduct::setScore(int score){
    this ->  score = score;
}

int PurchasedProduct::getProductId(){
    return this -> productId;
}
