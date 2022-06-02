//
//  SearchProduct.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef SearchProduct_hpp
#define SearchProduct_hpp
#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include "Product.hpp"
using namespace std;

class SearchProductUI{
private:
public:
    //input 
    string selectProduct(FILE *in_fp);
    //output
    void showInterface(FILE *out_fp);
};


// class: SearchProduct
// Descrption 상품 검색을 담당하는 control class 클래스 입니다.
class SearchProduct{
private:
    int nowSearchProduct;
    SearchProductUI ui;
public:
    SearchProduct(FILE * in_fp, FILE *out_fp);
    void startInterface();
    int showProduct(string name);
    int getNowSearchProduct();
};




#endif /* SearchProduct_hpp */
