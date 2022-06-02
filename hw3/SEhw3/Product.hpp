//
//  Product.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/01.
//

#ifndef Product_hpp
#define Product_hpp
#define MAX_STRING 32
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//class: Product
//Descrpition : this is class for product
class Product{
private:
    char name[MAX_STRING];
    char companyName[MAX_STRING];
    int productId; // product 배열에서의 인덱스 값
    int price;  // 가격
    int stockCount; // 현재 수량
    int count;  // 총 수량 = 판매 완료시 판매된 수량
    int score = 0;  // 구매 만족도의 합. 총 구매 만족도 / (총 수량 - 현재 수량) = 현재 구매 만족도

public:
    Product(string productName="", char companyName="",int productId =-1, int price=0, int count=0){
        this->name = productName;
        this->companyName = companyName;
        this -> productId = productId;
        this->price = price;
        this->count = count;
        this->stockCount = count;
    }
    void getProductDetail(FILE *out_fp); // 상품 디테일 정보 가져오는 함수. 상품 정보 출력해준다.
    void getSoldOutProductDetail();
    void getProductStat();
    void changeProductAmount();
    //void searchProduct(string productName);
    
    void buyProduct();
    string getName(){return this->name; }
    int getStockCount(){ return this -> stockCount; }
    void addScore(int score);
    string getCompanyName(){return this -> companyName;}
};




#endif /* Product_hpp */
