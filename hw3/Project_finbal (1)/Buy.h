#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include "Product.h"
#pragma once

class PurchasedProduct {
private:
	int productId;
	int score;
public:
	PurchasedProduct() = default;
	PurchasedProduct(int id);
	bool isPurchased();
	bool isRate();
	int getPurchasedProduct();
	void setProductId(int productId);
	void setScore(int score);
	int getProductId();
};

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


class SearchProductUI {
private:
public:
	//input
	string selectProduct();
	//output
	void showInterface();
};


// class: SearchProduct
// Descrption ��ǰ �˻��� ����ϴ� control class Ŭ���� �Դϴ�.
class SearchProduct {
private:
	int nowSearchProduct;
	SearchProductUI ui;
public:
	SearchProduct() ;
	void startInterface();
	int showProduct(string name);
	int getNowSearchProduct();
};



class BuyProductUI {
private:
public:
	void showInterface(string companayName, string pName);
};

//class : BuyProduct
//Description: ��ǰ ���Ÿ� ����ϴ� control class �Դϴ�.
class BuyProduct {
private:
	BuyProductUI ui;
public:
	BuyProduct(int nowProductId);
	void buyProductProcess(int productId);
};


class ShowPurchasedHistoryUI {
private:
public:
	ShowPurchasedHistoryUI() = default;
	void showInterface();
};


//class:ShowPurchasedHistory
// Descrtiption: ���ų��� ��ȸ�� ����ϴ� control class�Դϴ�.
class ShowPurchasedHistory {
private:
	ShowPurchasedHistoryUI ui;
public:
	ShowPurchasedHistory();
	void inquiryProductList();

};

class ScoreUI {
private:
public:
	int scoreProduct();
	//void showInterface(string companyName, string pName, int score);
};

class Score {
private:
	ScoreUI ui;
public:
	Score(int nowProductId);
	void addScore(int nowProductId, int score);

};
