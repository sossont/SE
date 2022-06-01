//
//  PurchasedProductCollection.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef PurchasedProductCollection_hpp
#define PurchasedProductCollection_hpp

#include <stdio.h>
#include "PurchasedProduct.hpp"

// class: PurchasedProductCollection
// Description: 한명의 회원이 구매한 상품을 모아놓는 클래스 입니다.
// 일단 배열로 구현했으나, 필요시 동적 할당 방법으로 바꿔 드릴게요
class PurchasedProductCollection{
private:
    PurchasedProduct PurchasedList[100];
    int PurchasedCount;
public:
    PurchasedProductCollection();
    void addNewProduct(int productId);
    void addProductScore(int productId ,int score);
    int getPurchasedCount();
    int getPurchasedProductId(int index);
};




#endif /* PurchasedProductCollection_hpp */
