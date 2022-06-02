//
//  ShowPurchaseHistory.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "ShowPurchaseHistory.hpp"
extern MemberCollection*  member_list;
extern Product productList[100];

void ShowPurchasedHistoryUI::showInterface(FILE *out_fp){
    char * out ="상품 구매 내역 조회\n";
    fprintf(out_fp, "%s", out);
    
}


ShowPurchasedHistory::ShowPurchasedHistory(FILE *out_fp){
    this ->inquiryProductList();
    
}


void ShowPurchasedHistory::inquiryProductList(){
    Member *nowUser = member_list -> activeMember;
    int myPurchasedCount = nowUser -> getPurchasedProductCollection().getPurchasedCount();
    int tmpPid = -1;
    for(int i =0; i< myPurchasedCount; i++){
        tmpPid = nowUser -> getPurchasedProductCollection().getPurchasedProductId(i);
        //int inquireProductId = tmpPid;
        //product
        productList[tmpPid].getProductDetail();
    }
}
