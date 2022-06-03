#include <stdio.h>
#include "Member.h"
#include "Product.h"
#pragma once

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
