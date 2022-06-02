//
//  buy.cpp
//  se_integreation
//
//  Created by 이다솜 on 2022/06/02.
//

#include "Buy.h"
#include "Member.h"

extern Product productList[100];
extern int productNum;
extern MemberCollection* member_list;
extern FILE* in_fp, *out_fp;

PurchasedProduct::PurchasedProduct(int id) {
	this->productId = id;
	score = -1;
}

bool PurchasedProduct::isRate() {
	if (this->score == -1) {
		return false;
	}
	else
		return true;
}

void PurchasedProduct::setProductId(int productId) {
	this->productId = productId;
}

void PurchasedProduct::setScore(int score) {
	this->score = score;
}

int PurchasedProduct::getProductId() {
	return this->productId;
}

//생성자
//구매한 물건 개수 0으로 초기화
PurchasedProductCollection::PurchasedProductCollection() {
	this->PurchasedCount = 0;
}

//새롭게 구매한 물건 추가
void PurchasedProductCollection::addNewProduct(int productId) {
	this->PurchasedList[this->PurchasedCount].setProductId(productId);
	this->PurchasedCount = this->PurchasedCount + 1;
}

void PurchasedProductCollection::addProductScore(int productId, int score) {
	// 한 유저의 구매 목록들 중, productId가 일치하는 PurchasedProduct 에 score 값을 넣어준다.
	for (int j = 0; j < this->PurchasedCount; j++) {
		if (this->PurchasedList[j].getProductId() == productId) {
			PurchasedList[j].setScore(score);
		}
	}


}

int PurchasedProductCollection::getPurchasedCount() {
	return this->PurchasedCount;
}

int PurchasedProductCollection::getPurchasedProductId(int index) {
	return PurchasedList[index].getProductId();
}

//Search Product

string SearchProductUI::selectProduct() {
	char tmp[100];
	fscanf(in_fp, "%s", tmp);
	string name(tmp);
	return name;
}

//SearchProudct 내부 함수 구현
SearchProduct::SearchProduct() {
	string nowSearchProductName = this->ui.selectProduct();
	this->showProduct(nowSearchProductName);
}

//SearchProudct 내부 함수 구현
int SearchProduct::getNowSearchProduct() {
	return this->nowSearchProduct;
}
int SearchProduct::showProduct(string name) {
	fprintf(out_fp, "4.1.상품 정보 검색\n> ");
	for (int i = 0; i < productNum; i++) {
		if (productList[i].getName() == name) {
			productList[i].getProductDetailWithSeller();
			this->nowSearchProduct = i;
			return i;
		}
	}
	// 상품을 찾지 못한 경우 -1 반환
	return -1;
}

/*

void BuyProductUI::showInterface(string companyName , string pName){
	char * out ="4.2. 상품 구매\n";
	fprintf(out_fp, "%s\n", out);
	fprintf(out_fp, "%s %s\n", companyName.c_str(),pName.c_str());
	return ;
}
*/

//BuyProduct class 의 내부함수 구현
BuyProduct::BuyProduct(int nowProductId) {
	this->buyProductProcess(nowProductId);
	string pName = productList[nowProductId].getName();
	string companyName = productList[nowProductId].getSellerName();
	fprintf(out_fp, "4.2. 상품 구매\n> ");
	fprintf(out_fp, "%s %s\n", companyName.c_str(), pName.c_str());
}

void BuyProduct::buyProductProcess(int productId) {
	//재고가 하나 이상일 때 구매
	if (productList[productId].getStockCount() > 0) {
		productList[productId].changeProductAmount();
	}
	else {
		return;
	}
	//구매 완료 후 구매한 상품 목록에 추가
	//구매자 본인 정보 받아옴
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection().addNewProduct(productId);
}


/*
void ShowPurchasedHistoryUI::showInterface(FILE *out_fp){
	char * out ="상품 구매 내역 조회\n";
	fprintf(out_fp, "%s", out);

}

*/

ShowPurchasedHistory::ShowPurchasedHistory() {
	this->inquiryProductList();

}


void ShowPurchasedHistory::inquiryProductList() {
	Member *nowUser = member_list->activeMember;
	int myPurchasedCount = nowUser->getPurchasedProductCollection().getPurchasedCount();
	int tmpPid = -1;
	fprintf(out_fp, "4.3. 상품 구매 내역 조회\n> ");
	cout << myPurchasedCount;
	cout << nowUser->getPurchasedProductCollection().getPurchasedCount();
	for (int i = 0; i < myPurchasedCount; i++) {
		
		tmpPid = nowUser->getPurchasedProductCollection().getPurchasedProductId(i);
		int inquireProductId = tmpPid;
		//product
		productList[tmpPid].getProductDetailWithSeller();
	}
}

/*
void ScoreUI::showInterface(FILE *out_fp, string companyName, string pName, int score){
	char *out = "상품 구매만족도 평가\n";
	fprintf(out_fp, "%s", out);

	fprintf(out_fp, "%s %s %d", companyName.c_str(),pName.c_str() ,score);
	return;
}
 */


int ScoreUI::scoreProduct() {
	int score;
	fscanf(in_fp, "%d", &score);
	return score;
}



//Score class의 함수 구현
Score::Score(int nowProductId) {
	int inScore = ui.scoreProduct();
	this->addScore(nowProductId, inScore);
	string pName = productList[nowProductId].getName();
	string companyName = productList[nowProductId].getSellerName();
	fprintf(out_fp, "4.4. 상품 구매만족도 평가\n> ");
	fprintf(out_fp, "%s %s %d \n\n", companyName.c_str(), pName.c_str(), inScore);
}


void Score::addScore(int nowProductId, int score) {
	//User의 구매 목록에 User가 매긴 별점을 저장한다.
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection().addProductScore(nowProductId, score);

	//Product의 객체에 새롭게 추가한 score값 저장.
	productList[nowProductId].addScore(score);
};
