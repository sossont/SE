//
//  ShowPurchaseHistory.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef ShowPurchaseHistory_hpp
#define ShowPurchaseHistory_hpp


#include <stdio.h>
#include "Member.hpp"
#include "Product.hpp"
class ShowPurchasedHistoryUI{
private:
public:
    ShowPurchasedHistoryUI();
    void showInterface(FILE *out_fp);
};


//class:ShowPurchasedHistory
// Descrtiption: 구매내역 조회를 담당하는 control class입니다.
class ShowPurchasedHistory{
private:
    ShowPurchasedHistoryUI ui;
public:
    ShowPurchasedHistory(FILE *out_fp);
    void inquiryProductList();
    
};





#endif /* ShowPurchaseHistory_hpp */
