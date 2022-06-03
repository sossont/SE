#include "Buy.h"
#include "Member.h"

extern vector<Product*> productList;
extern int productNum;
extern MemberCollection* member_list;
extern FILE* in_fp, *out_fp;


PurchasedProduct::PurchasedProduct() {
	this->productId = -1;
	score = -1;
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

PurchasedProductCollection::PurchasedProductCollection() {
	this->PurchasedCount = 0;
}

// Function : addNewProduct
// Description: PurchasedCollection에 새로운 구매한 물건을 추가한다. 
// Created: 2022/5/31 02:36
// Author: 이다솜
void PurchasedProductCollection::addNewProduct(int productId) {
	int cnt = this->PurchasedCount;
	this->PurchasedList[cnt].setProductId(productId);
	this->PurchasedCount = cnt + 1;
}

// Function : addProductScore
// Description: 구매한 상품 목록에서 product id 가 일치하는 상품의 id에 평가 점수를 저장함.
// Created: 2022/5/31 02:36
// Author: 이다솜
void PurchasedProductCollection::addProductScore(int productId, int score) {
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

// Function : SearchProductUI
// Description: 상품 검색을 위한 상품 이름을 입력받는다. 
// Created: 2022/5/31 02:46
// Author: 이다솜
string SearchProductUI::selectProduct() {
	char tmp[100];
	fscanf(in_fp, "%s", tmp);
	string name(tmp);
	return name;
}


SearchProduct::SearchProduct() {
	string nowSearchProductName = this->ui.selectProduct();
	this->showProduct(nowSearchProductName);
}


int SearchProduct::getNowSearchProduct() {
	return this->nowSearchProduct;
}

// Function : showProduct
// Description: 상품 목록에서 이름이 일치하는 상품의 정보를 찾아와 출력한다.
// Created: 2022/5/31 02:40
// Author: 이다솜
int SearchProduct::showProduct(string name) {
	fprintf(out_fp, "4.1.상품 정보 검색\n> ");
	for (int i = 0; i < productNum; i++) {
		//cout << productList[i]->getName();
		if (productList[i]->getName() == name) {
			productList[i]->getProductDetailWithSeller();
			this->nowSearchProduct = i;
			return i;
		}
	}
	// 상품을 찾지 못한 경우 -1 반환
	return -1;
}

// Function : BuyProduct
// Description: BuyProduct class의 생성자이다.
// Created: 2022/5/31 02:40
// Author: 이다솜
BuyProduct::BuyProduct(int nowProductId) {
	this->buyProductProcess(nowProductId);
	string productName = productList[nowProductId]->getName();
	string sellerName = productList[nowProductId]->getSellerName();
	fprintf(out_fp, "4.2. 상품 구매\n> ");
	fprintf(out_fp, "%s %s\n\n", sellerName.c_str(), productName.c_str());
}

// Function : buyProductProcess
// Description: 물건을 구매하고 이에 따른 재고를 변경시켜 준다. 
// Created: 2022/5/31 02:40
// Author: 이다솜
void BuyProduct::buyProductProcess(int productId) {
	if (productList[productId]->getStockCount() > 0) {
		productList[productId]->changeProductAmount();
	}
	else {
		return;
	}
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection()->addNewProduct(productId);
}


ShowPurchasedHistory::ShowPurchasedHistory() {
	this->inquiryProductList();
}

// Function : inquiryProductList
// Description: 로그인한 유저의 구매 내역을 조회한다. 
// Created: 2022/5/31 02:40
// Author: 이다솜
void ShowPurchasedHistory::inquiryProductList() {
	Member *nowUser = member_list->activeMember;
	PurchasedProductCollection* tmpCollection = nowUser->getPurchasedProductCollection();
	int myPurchasedCount = tmpCollection->getPurchasedCount();
	int tmpPid = -1;
	fprintf(out_fp, "4.3. 상품 구매 내역 조회\n> ");
	for (int i = 0; i < myPurchasedCount; i++) {
		tmpPid = tmpCollection->getPurchasedProductId(i);
		int inquireProductId = tmpPid;
		//product
		productList[tmpPid]->getProductDetailWithSeller();
	}
}

// Function : scoreProduct
// Description: 구매 만족도 평가를 위한 점수를 받는다. 
// Created: 2022/5/31 02:40
// Author: 이다솜
int ScoreUI::scoreProduct() {
	int score;
	fscanf(in_fp, "%d", &score);
	return score;
}
// Function :selectName
// Description: 구매 만족도 평가를 위한 상품에 점수를 받는다. 
// Created: 2022/5/31 02:40
// Author: 이다솜
string ScoreUI::selectName() {
	char tmp[100];
	fscanf(in_fp, "%s", &tmp);
	string name = string(tmp);
	return name;
}

// Function: Score
// Description: Score class의 생성자이다. 
// Created: 2022/5/31 02:40
// Author: 이다솜
Score::Score(int nowProductId) {
	string inName = ui.selectName();
	int inScore = ui.scoreProduct();
	int nowPid = 0;
	for (int i = 0; i < productNum; i++) {
		if (productList[i]->getName() == inName) {
			nowPid = i;
			break;
		}
	}
	this->addScore(nowPid, inScore);
	string pName = productList[nowProductId]->getName();
	string companyName = productList[nowProductId]->getSellerName();
	fprintf(out_fp, "4.4. 상품 구매만족도 평가\n> ");
	fprintf(out_fp, "%s %s %d \n\n", companyName.c_str(), pName.c_str(), inScore);
}

// Function: addScore
// Description: 입력한 별점을 저장한다. 
// Created: 2022/5/31 02:40
// Author: 이다솜
void Score::addScore(int nowProductId, int score) {
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection()->addProductScore(nowProductId, score);
	productList[nowProductId]->addScore(score);
};
