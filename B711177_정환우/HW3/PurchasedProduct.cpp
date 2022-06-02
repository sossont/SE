#include "PurchasedProduct.h"

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