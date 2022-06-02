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
    string sellerName;
    string productName;
    string companyName;
    int productId;
    int price;  // 가격
    int stockCount; // 현재 수량
    int count;  // 총 수량 = 판매 완료시 판매된 수량
    int score = 0;  // 구매 만족도의 합. 총 구매 만족도 / (총 수량 - 현재 수량) = 현재 구매 만족도
public:
    Product() = default;
    Product(string sellerName, string productName, string companyName, int productId, int price, int count);
    void getProductDetail(); // 상품 디테일 정보 가져오는 함수. 상품 정보 출력해준다.
    void getSoldOutProductDetail();
    void getProductStat();
    
    void changeProductAmount();
    
    //void searchProduct(string productName);
    void addScore(int score);
    float getAvgScore();
    int getStockCount(){ return this -> stockCount; }
    string getCompanyName(){return this -> companyName;}
    string getProductName(){return this-> productName; }
    string getSellerName(){return this -> sellerName;}
    
};




#endif /* Product_hpp */
