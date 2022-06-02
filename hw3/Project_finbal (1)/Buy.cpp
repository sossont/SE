//
//  buy.cpp
//  se_integreation
//
//  Created by �̴ټ� on 2022/06/02.
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

//������
//������ ���� ���� 0���� �ʱ�ȭ
PurchasedProductCollection::PurchasedProductCollection() {
	this->PurchasedCount = 0;
}

//���Ӱ� ������ ���� �߰�
void PurchasedProductCollection::addNewProduct(int productId) {
	this->PurchasedList[this->PurchasedCount].setProductId(productId);
	this->PurchasedCount = this->PurchasedCount + 1;
}

void PurchasedProductCollection::addProductScore(int productId, int score) {
	// �� ������ ���� ��ϵ� ��, productId�� ��ġ�ϴ� PurchasedProduct �� score ���� �־��ش�.
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

//SearchProudct ���� �Լ� ����
SearchProduct::SearchProduct() {
	string nowSearchProductName = this->ui.selectProduct();
	this->showProduct(nowSearchProductName);
}

//SearchProudct ���� �Լ� ����
int SearchProduct::getNowSearchProduct() {
	return this->nowSearchProduct;
}
int SearchProduct::showProduct(string name) {
	fprintf(out_fp, "4.1.��ǰ ���� �˻�\n> ");
	for (int i = 0; i < productNum; i++) {
		if (productList[i].getName() == name) {
			productList[i].getProductDetailWithSeller();
			this->nowSearchProduct = i;
			return i;
		}
	}
	// ��ǰ�� ã�� ���� ��� -1 ��ȯ
	return -1;
}

/*

void BuyProductUI::showInterface(string companyName , string pName){
	char * out ="4.2. ��ǰ ����\n";
	fprintf(out_fp, "%s\n", out);
	fprintf(out_fp, "%s %s\n", companyName.c_str(),pName.c_str());
	return ;
}
*/

//BuyProduct class �� �����Լ� ����
BuyProduct::BuyProduct(int nowProductId) {
	this->buyProductProcess(nowProductId);
	string pName = productList[nowProductId].getName();
	string companyName = productList[nowProductId].getSellerName();
	fprintf(out_fp, "4.2. ��ǰ ����\n> ");
	fprintf(out_fp, "%s %s\n", companyName.c_str(), pName.c_str());
}

void BuyProduct::buyProductProcess(int productId) {
	//��� �ϳ� �̻��� �� ����
	if (productList[productId].getStockCount() > 0) {
		productList[productId].changeProductAmount();
	}
	else {
		return;
	}
	//���� �Ϸ� �� ������ ��ǰ ��Ͽ� �߰�
	//������ ���� ���� �޾ƿ�
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection().addNewProduct(productId);
}


/*
void ShowPurchasedHistoryUI::showInterface(FILE *out_fp){
	char * out ="��ǰ ���� ���� ��ȸ\n";
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
	fprintf(out_fp, "4.3. ��ǰ ���� ���� ��ȸ\n> ");
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
	char *out = "��ǰ ���Ÿ����� ��\n";
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



//Score class�� �Լ� ����
Score::Score(int nowProductId) {
	int inScore = ui.scoreProduct();
	this->addScore(nowProductId, inScore);
	string pName = productList[nowProductId].getName();
	string companyName = productList[nowProductId].getSellerName();
	fprintf(out_fp, "4.4. ��ǰ ���Ÿ����� ��\n> ");
	fprintf(out_fp, "%s %s %d \n\n", companyName.c_str(), pName.c_str(), inScore);
}


void Score::addScore(int nowProductId, int score) {
	//User�� ���� ��Ͽ� User�� �ű� ������ �����Ѵ�.
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection().addProductScore(nowProductId, score);

	//Product�� ��ü�� ���Ӱ� �߰��� score�� ����.
	productList[nowProductId].addScore(score);
};
