//
//  BuyProduct.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "BuyProduct.hpp"
extern Product productList[100];

void BuyProductUI::showInterface(FILE *out_fp, string companyName , string pName){
    char * out ="4.2. 상품 구매\n";
    fprintf(out_fp, "%s\n", out);
    fprintf(out_fp, "%s %s\n", companyName.c_str(),pName.c_str());
    return ;
}



//BuyProduct class 의 내부함수 구현
BuyProduct::BuyProduct(int nowProductId, FILE *out_fp){
    this ->buyProductProcess(nowProductId);
    string pName = productList[nowProductId].getName();
    string companyName = productList[nowProductId].getCompanyName();
    this -> ui.showInterface(out_fp, companyName, pName);
}


void BuyProduct::buyProductProcess(int productId){
    //재고가 하나 이상일 때 구매
    if (productList[productId].getStockCount() >0 ){
        productList[productId].changeProductAmount();
    }
    else{
        return ;
    }
    //구매 완료 후 구매한 상품 목록에 추가
    //구매자 본인 정보 받아옴
    Member *nowUser = member_list -> activeMember;
    nowUser ->getPurchasedProductCollection().addNewProduct(productId);
}
