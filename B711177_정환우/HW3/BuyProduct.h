#include <stdio.h>
#include <iostream>
#pragma once

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include "Product.h"
#include "Member.h"

using namespace std;

class BuyProductUI{
private:
public:
    void showInterface(FILE *out_fp,string companayName, string pName);
};




//class : BuyProduct
//Description: 상품 구매를 담당하는 control class 입니다.
class BuyProduct{
private:
    BuyProductUI ui;
public:
    BuyProduct(int nowProductId ,FILE *out_fp);
    void buyProductProcess(int productId);
};