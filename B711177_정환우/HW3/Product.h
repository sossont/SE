#include <string>

// Class : Product
// Description: 상품 정보 저장하는 클래스
// Created: 2022/5/31 18:00
// Author: 정환우

using namespace std;
class Product
{
private:
    string name;
    string companyName;
    int productId;
    int price;      // 가격
    int stockCount; // 현재 수량
    int count;      // 총 수량 = 판매 완료시 판매된 수량
    int score = 0;  // 구매 만족도의 합. 총 구매 만족도 / (총 수량 - 현재 수량) = 현재 구매 만족도

public:
    Product(string productName = "", string companyName = "", int productId = -1, int price = 0, int count = 0)
    {
        this->productId = productId;
        this->name = productName;
        this->companyName = companyName;
        this->price = price;
        this->count = count;
        this->stockCount = count;
    };
    void getProductDetail(); // 상품 디테일 정보 가져오는 함수. 상품 정보 출력해준다.
    void getSoldOutProductDetail();
    void getProductStat();
};
