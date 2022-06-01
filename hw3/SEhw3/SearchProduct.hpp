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

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

class SearchProductUI{
private:
public:
    void selectProduct();
    void startInterface();
};


// class: SearchProduct
// Descrption 상품 검색을 담당하는 control class 클래스 입니다.
class SearchProduct{
private:
    SearchProductUI ui;
public:
    SearchProduct();
    void startInterface();
    int showProduct(string name);
};



#endif /* SearchProduct_hpp */
