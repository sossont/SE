//
//  BuyProduct.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef BuyProduct_hpp
#define BuyProduct_hpp

#include <stdio.h>
#include <iostream>


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include "Product.hpp"
#include "Member.hpp"

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







#endif /* BuyProduct_hpp */
