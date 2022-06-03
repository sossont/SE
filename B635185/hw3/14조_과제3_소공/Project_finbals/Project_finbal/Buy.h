#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include "Product.h"
#pragma once

// Class :PurchasedProduct
// Description : 구매한 상품을 저장하는 클래스 
// Created : 2022/06/02 02:24
// Author : 이다솜
class PurchasedProduct {
private:
	int productId;
	int score;
public:
	PurchasedProduct();
	void setProductId(int productId);
	void setScore(int score);
	int getProductId();
};

// Class :PurchasedProductCollection
// Description : 구매한 상품을 리스트로 관리하는 Collection class입니다.  
// Created : 2022/06/02 02:24
// Author : 이다솜
class PurchasedProductCollection {
private:
	PurchasedProduct PurchasedList[100];
	int PurchasedCount;
public:
	PurchasedProductCollection();
	void addNewProduct(int productId);
	void addProductScore(int productId, int score);
	int getPurchasedCount();
	int getPurchasedProductId(int index);
};

// Class :SearchProductUI
// Description : boundary class for SearchProduct
// Created : 2022/06/02 02:24
// Author : 이다솜
class SearchProductUI {
private:
public:
	//input
	string selectProduct();
};

// Class : SearchProduct 
// Description : control class for search Product
// Created : 2022/06/02 01:18
// Author : 이다솜
class SearchProduct {
private:
	int nowSearchProduct;
	SearchProductUI ui;
public:
	SearchProduct();
	int showProduct(string name);
	int getNowSearchProduct();
};


// Class :BuyProductUI
// Description : boundary class for BuyProduct
// Created : 2022/06/02 02:24
// Author : 이다솜
class BuyProductUI {
private:
public:
};

// Class : BuyProduct
// Description : control class for buy Product
// Created : 2022/06/02 01:18
// Author : 이다솜
class BuyProduct {
private:
	BuyProductUI ui;
public:
	BuyProduct(int nowProductId);
	void buyProductProcess(int productId);
};

// Class :ShowPurchasedHistoryU
// Description : boundary class for ShowPurchasedHistory
// Created : 2022/06/02 02:24
// Author : 이다솜
class ShowPurchasedHistoryUI {
private:
public:
	ShowPurchasedHistoryUI() = default;
};

// Class : ShowPurchasedHistory
// Description : control class for show purchase history 
// Created : 2022/06/02 01:18
// Author : 이다솜
class ShowPurchasedHistory {
private:
	ShowPurchasedHistoryUI ui;
public:
	ShowPurchasedHistory();
	void inquiryProductList();

};

// Class :ScoreUI
// Description : boundary class for Score
// Created : 2022/06/02 02:24
// Author : 이다솜
class ScoreUI {
private:
public:
	int scoreProduct();
	string selectName();
	//void showInterface(string companyName, string pName, int score);
};

// Class : Score
// Description : control class for score product
// Created : 2022/06/02 02:33
// Author : 이다솜
class Score {
private:
	ScoreUI ui;
public:
	Score(int nowProductId);
	void addScore(int nowProductId, int score);

};
