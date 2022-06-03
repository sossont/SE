#include "Product.h"
#include <cmath>

// Main 함수에서 사용하는 변수들 공유해서 사용하기 위함
extern int productNum;
extern vector<Product*> productList;
extern FILE* in_fp, *out_fp;
extern ProductCollection* now_product_collection;

Product::Product(string sellerID, string productName, string companyName, int productId, int price, int count) {
	this->sellerID = sellerID;
	this->productId = productId;
	this->productName = productName;
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
	fprintf(out_fp, "%s %s %d %d\n\n", this->productName.c_str(), this->companyName.c_str(), this->price, this->stockCount);
}

// Function : getProductDetailWithSeller
// Description: 상품 상세 정보및 판매자 정보를 출력하는 함수.
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getProductDetailWithSeller() {
	int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
	int totalPrice = this->price * sellCount;
	double averageScore = 0;  // 만약 판매량이 0개이면 score 가 0일 것
	if (sellCount != 0)
	{
		averageScore = double(this->score) / double(sellCount); // 평균 구매만족도 = 총 만족도 / 판매 수량
	}
	int averageScoreRounded = round(averageScore); // cmath 라이브러리를 이용하여 평균 구매만족도에서 첫쨰 자리를 반올림 한 후에 정수형으로 변환.
	fprintf(out_fp, "%s %s %s %d %d %d\n\n", this->sellerID.c_str(), this->productName.c_str(), this->companyName.c_str(), this->price, this->stockCount, averageScoreRounded);
}

// Function : getSoldOutProductDetail
// Description: 판매 완료된 상품 조회 하는 함수
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getSoldOutProductDetail() {
	// stockCount 가 0이 아니면 판매 완료된 상품이 아니다.

	if (this->stockCount != 0) {
		return;
	}
	fprintf(out_fp, "%s %s %d %d %d\n\n", this->productName.c_str(), this->companyName.c_str(), this->price, this->count, this->score);
}

// Function : getAllProductStats
// Description: 판매 상품 통계 출력하는 함수.
// Created: 2022/5/31 18:00
// Author: 정환우
void Product::getProductStat() {
	int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
	int totalPrice = this->price * sellCount;
	double averageScore = 0;    // 만약 판매량이 0개이면 score 가 0일 것
	if (sellCount != 0)
	{
		averageScore = double(this->score) / double(sellCount); // 평균 구매만족도 = 총 만족도 / 판매 수량
	}
	int averageScoreRounded = round(averageScore); // cmath 라이브러리를 이용하여 평균 구매만족도에서 첫쨰 자리를 반올림 한 후에 정수형으로 변환.
	fprintf(out_fp, "%s %d %d\n\n", this->productName.c_str(), totalPrice, averageScoreRounded);
}

void Product::addScore(int score) {
	this->score += score;
}

void Product::changeProductAmount() {

	this->stockCount = this->stockCount - 1;
}

// Function : getAllProductStats
// Description: 컬렉션 순회 돌면서, 판매 통계 출력 한다.
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getAllProductStats() {
	for (auto product : ownedProduct) {
		product->getProductStat();
	}
}

// Function : getAllProducts
// Description: 등록 상품 조회하는 함수로, 컬렉션 순회를 돌면서 상품 정보 출력한다.
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getAllProducts() {
	for (auto product : ownedProduct) {
		product->getProductDetail();
	}
}

// Function : getSoldOutProducts
// Description: 컬렉션 순회 돌며 판매 완료된 상품 상세 정보 출력
// Created: 2022/5/31 18:00
// Author: 정환우
void ProductCollection::getSoldOutProducts() {
	for (auto product : ownedProduct) {
		product->getSoldOutProductDetail();
	}
}

// Function : addNewProduct
// Description: 새로운 상품 추가하는 함수로, 새로운 상품 생성후 컬렉션에 추가한다. 전체 상품에 추가하기 위해 product 반환
// Created: 2022/5/31 18:00
// Author: 정환우

void ProductCollection::addNewProduct(string sellerID, string productName, string companyName, int price, int count) {
	Product *product = new Product(sellerID, productName, companyName, productNum, price, count);
	// 전역 배열에 추가
	product->getProductDetail();
	productList.push_back(product);
	productNum++;
	this->ownedProduct.push_back(product);
}

void AddProductUI::addProduct(string sellerID, string productName, string companyName, int price, int count) {
	fprintf(out_fp, "3.1. 판매 의류 등록\n> ");
	AddProduct addProduct;
	addProduct.addProduct(sellerID, productName, companyName, price, count);
}

void AddProduct::addProduct(string sellerID, string productName, string companyName, int price, int count) {
	// Member의 productCollection
	now_product_collection->addNewProduct(sellerID, productName, companyName, price, count);
}

// Function : calculateAllProductStats
// Description: Boundary 클래스 구현. 통계를 위한 control class 함수 호출.
// Created: 2022/6/2/13:20
// Author: 정환우
void CalculateUI::calculateAllProductStats() {
	fprintf(out_fp, "5.1 판매 상품 통계\n> ");
	Calculate calculate;
	calculate.calculateAllProductStats();
}

// Function : calculateAllProductStats
// Description: 컬렉션에서 통계 조회 하기
// Created: 2022/6/2/13:20
// Author: 정환우
void Calculate::calculateAllProductStats() {
	now_product_collection->getAllProductStats();
}

// Function : getProductList
// Description: 등록 상품 조회를 위한 control class 함수 호출
// Created: 2022/6/2/13:20
// Author: 정환우
void GetProductsUI::getProductList() {
	GetProducts getProducts;
	getProducts.getProductList();
}

// Function : getProductList
// Description: 컬렉션에서 모든 상품 상세 조회.
// Created: 2022/6/2/13:20
// Author: 정환우
void GetProducts::getProductList() {
	fprintf(out_fp, "3.2. 등록 상품 조회\n> ");
	now_product_collection->getAllProducts();
}

// Function : getSoldOutProducts
// Description: 판매 완료 상품 조회를 위한 control class 함수 호출
// Created: 2022/6/2/13:20
// Author: 정환우
void GetSoldOutProductUI::getSoldOutProducts() {
	GetSoldOutProduct getSoldOutProduct;
	getSoldOutProduct.getSoldOutProducts();
}

// Function : getSoldOutProducts
// Description: 컬렉션에서 판매 완료된 상품 호출
// Created: 2022/6/2/13:20
// Author: 정환우
void GetSoldOutProduct::getSoldOutProducts() {
	fprintf(out_fp, "3.3. 판매 완료 상품 조회\n> ");
	now_product_collection->getSoldOutProducts();
}

