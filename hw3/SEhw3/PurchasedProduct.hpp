//
//  PurchasedProduct.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef PurchasedProduct_hpp
#define PurchasedProduct_hpp

#include <stdio.h>


class PurchasedProduct{
private:
    int productId;
    int score;
public:
    PurchasedProduct(int id = -1);
    bool isPurchased();
    bool isRate();
    int getPurchasedProduct();
    void setProductId(int productId);
    void setScore(int score);
    int getProductId();
};



#endif /* PurchasedProduct_hpp */
