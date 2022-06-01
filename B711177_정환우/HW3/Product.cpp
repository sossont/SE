#include "Product.h"

extern int productNum;
extern Product productList[100];
extern FILE* in_fp, *out_fp;

Product::Product(string productName, string companyName, int productId, int price, int count) {
    this->productId = productId;
    this->name = productName;
    this->companyName = companyName;
    this->price = price;
    this->count = count;
    this->stockCount = count;
}

// Function : getProductDetail
// Description: 상품 상세 정보를 출력하는 함수.
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getProductDetail() {
    fprintf(out_fp, "%s %s %d %d", this->name.c_str(), this->companyName.c_str(), this->price, this->stockCount);
    // cout << this->name << " " << this->companyName << " " << this->price << " " << this->stockCount << endl;
}

// Function : getSoldOutProductDetail
// Description: 판매 완료된 상품 조회 하는 함수
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getSoldOutProductDetail() {
    // stockCount 가 0이 아니면 판매 완료된 상품이 아니다.

    if (this->stockCount != 0){
        return;
    }

    cout << this->name << " " << this->companyName << " " << this -> price << " " << this->count << " " << this->score << endl;
}

// Function : getProductStat
// Description: 판매 상품 통계 출력하는 함수.
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getProductStat() {
    int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
    int totalPrice = this->price * sellCount;
    int averageScore = this->score / sellCount; // 평균 구매만족도 = 총 만족도 / 판매 수량
    cout << this->name << " " << totalPrice << " " << averageScore << endl;
}

// Function : getProductStat
// Description: 컬렉션 순회 돌면서, 판매 통계 출력 한다.
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getProductStat() {
    for (auto product : ownedProduct) {
        product.getProductStat();
    }
}

// Function : getAllProduct
// Description: 등록 상품 조회하는 함수로, 컬렉션 순회를 돌면서 상품 정보 출력한다.
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getAllProduct() {
    for (auto product : ownedProduct) {
        product.getProductDetail();
    }
}

// Function : getSoldOutProduct
// Description: 컬렉션 순회 돌며 판매 완료된 상품 상세 정보 출력
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getSoldOutProducts() {
    for (auto product : ownedProduct) {
        product.getSoldOutProductDetail();
    }
}

// Function : addNewProduct
// Description: 새로운 상품 추가하는 함수로, 새로운 상품 생성후 컬렉션에 추가한다. 전체 상품에 추가하기 위해 product 반환
// Created: 2022/5/31 18:00
// Author: 정환우

void ProductCollection::addNewProduct(string productName, string companyName, int price, int count) {
    Product product = *new Product(productName, companyName, productNum, price, count);
    // 전역 배열에 추가
    product.getProductDetail();
    productList[productNum++] = product;
    this->ownedProduct.push_back(product);
}

void AddProductUI::addProduct(string productName, string companyName, int price, int count) {
    fprintf(out_fp, "3.1. 판매 의류 등록\n");
    AddProduct addProduct;
    addProduct.addProduct(productName, companyName, price, count);
}

void AddProduct::addProduct(string productName, string companyName, int price, int count) {
    ProductCollection productCollection;    // Member의 productCollection
    productCollection.addNewProduct(productName,companyName,price,count);
}

void CalculateUI::calculate() {
    fprintf(out_fp, "5.1 판매 상품 통계\n");
}

void Calculate::calculate() {

}

void GetProductsUI::getProducts() {
    fprintf(out_fp, "3.2. 등록 상품 조회\n");
    GetProducts getProducts;
    getProducts.getProducts();
}

void GetProducts::getProducts() {
    ProductCollection productCollection;
    productCollection.getAllProduct();
}

void GetSoldOutProduct::getSoldOutProduct() {
    fprintf(out_fp, "3.3. 판매 완료 상품 조회\n");
}

void GetSoldOutProductUI::getSoldOutProduct() {

}