#ifndef UNTITLED2_PRODUCT_H
#define UNTITLED2_PRODUCT_H
#define MAX_STRING 32
#include <vector>
#include <string>
#include <iostream>
#pragma once

using namespace std;

// Class : Product
// Description: 상품 정보 저장하는 클래스
// Created: 2022/5/31 18:00
// Author: 정환우

class Product {
private:
	string sellerID;
	string productName;
	string companyName;
	int productId;
	int price;  // 가격
	int stockCount; // 현재 수량
	int count;  // 총 수량 = 판매 완료시 판매된 수량
	int score = 0;  // 구매 만족도의 합. 총 구매 만족도 / (총 수량 - 현재 수량) = 현재 구매 만족도

public:
	Product() = default;
	Product(string sellerID, string productName, string companyName, int productId, int price, int count);
	void getProductDetail(); // 상품 디테일 정보 가져오는 함수. 상품 정보 출력해준다.
	void getSoldOutProductDetail();
	void getProductStat();
	void changeProductAmount();

	string getName() { return this->productName; }
	int getStockCount() { return this->stockCount; }
	void addScore(int score);
	string getSellerName() { return this->sellerID; }
	void getProductDetailWithSeller();

};

// Class : ProductCollection
// Description : 판매자가 판매한 상품들을 저장해놓는 컬렉션
// Created : 2022/5/31 18:00
// Author : 정환우
class ProductCollection {
private:
	vector<Product*> ownedProduct;

public:
	ProductCollection() = default;
	void addNewProduct(string
		sellerID, string productName, string companyName, int price, int count); // 3.1 판매 상품 등록. 상품명, 제작회사명, 가격, 수량
	void getAllProducts(); // 3.2 등록 상품 조회. 모든 ownedProduct 순회하면서 상품명, 제작회사명, 가격, 수량 출력하면 된다.
	void getSoldOutProducts();   // 3.3 판매 완료 상품 조회
	void getAllProductStats();  // 5.1 판매 상품 통계 출력하는 함수.
};

// Class : AddProductUI
// Description : boundary class for add product
// Created : 2022/06/02 01:18
// Author : 정환우

class AddProductUI {
public:
	AddProductUI() = default;
	void addProduct(string sellerID, string productName, string companyName, int price, int count);
};

// Class : AddProduct
// Description : control class for add product
// Created : 2022/06/02 01:18
// Author : 정환우
class AddProduct {
public:
	AddProduct() = default;
	void addProduct(string sellerID, string productName, string companyName, int price, int count);
};

// Class : CalculateUI
// Description : boundary class for getting all products stats
// Created : 2022/06/02 01:18
// Author : 정환우
class CalculateUI {
public:
	CalculateUI() = default;
	void calculateAllProductStats();
};

// Class : Calculate
// Description : control class for getting all products stats
// Created : 2022/06/02 01:18
// Author : 정환우
class Calculate {
public:
	Calculate() = default;
	void calculateAllProductStats();
};

// Class : GetProductsUI
// Description : boundary class for getting product list
// Created : 2022/06/02 01:18
// Author : 정환우
class GetProductsUI {
public:
	GetProductsUI() = default;
	void getProductList();
};

// Class : GetProducts
// Description : control class for getting product list
// Created : 2022/06/02 01:18
// Author : 정환우
class GetProducts {
public:
	GetProducts() = default;
	void getProductList();
};

// Class : GetSoldOutProductUI{
// Description : boundary class for getting sold out product list
// Created : 2022/06/02 01:18
// Author : 정환우
class GetSoldOutProductUI {
public:
	GetSoldOutProductUI() = default;
	void getSoldOutProducts();
};

// Class : GetSoldOutProduct
// Description : control class for getting sold out product list
// Created : 2022/06/02 01:18
// Author : 정환우
class GetSoldOutProduct {
public:
	GetSoldOutProduct() = default;
	void getSoldOutProducts();
};
#endif