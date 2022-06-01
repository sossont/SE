//
//  SearchProduct.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "SearchProduct.hpp"

//SearchProductUi 내부함수 구현


void SearchProductUI::SelectProduct(){
    
    
}

void

//SearchProudct 내부 함수 구현
SearchProduct::SearchProduct(){
   this -> ui.startInterface()
}


int SearchProduct::showProduct(string name){
    for(int i=0; i < productNum; i++){
        if(productList[i].getName() == name){
            productList[i].getProductDetail();
            return i;
        }
    }
    // 상품을 찾지 못한 경우 -1 반환
    return -1;
}
