//
//  SearchProduct.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "SearchProduct.hpp"

//SearchProductUi 내부함수 구현
extern Product productList[100];
extern int productNum = 0;

string SearchProductUI::selectProduct(FILE* in_fp){
    char tmp[100];
    fscanf(in_fp, "%s", tmp);
    string name(tmp);
    return name;
}

void SearchProductUI::showInterface(FILE* out_fp){
    char* out = "4.1. 상품 정보 검색\n";
    fprintf(out_fp, "%s", out);
}

//SearchProudct 내부 함수 구현
SearchProduct::SearchProduct(FILE * in_fp, FILE* out_fp){
    string nowSearchProduct = this -> ui.selectProduct(in_fp);
    this -> nowSearchProduct = this -> showProduct(nowSearchProduct);
    ui.showInterface(out_fp);
    
}

int SearchProduct::getNowSearchProduct(){
    return this ->  nowSearchProduct;
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
