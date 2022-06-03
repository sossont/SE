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
// Description: PurchasedCollection�� ���ο� ������ ������ �߰��Ѵ�. 
// Created: 2022/5/31 02:36
// Author: �̴ټ�
void PurchasedProductCollection::addNewProduct(int productId) {
	int cnt = this->PurchasedCount;
	this->PurchasedList[cnt].setProductId(productId);
	this->PurchasedCount = cnt + 1;
}

// Function : addProductScore
// Description: ������ ��ǰ ��Ͽ��� product id �� ��ġ�ϴ� ��ǰ�� id�� �� ������ ������.
// Created: 2022/5/31 02:36
// Author: �̴ټ�
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
// Description: ��ǰ �˻��� ���� ��ǰ �̸��� �Է¹޴´�. 
// Created: 2022/5/31 02:46
// Author: �̴ټ�
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
// Description: ��ǰ ��Ͽ��� �̸��� ��ġ�ϴ� ��ǰ�� ������ ã�ƿ� ����Ѵ�.
// Created: 2022/5/31 02:40
// Author: �̴ټ�
int SearchProduct::showProduct(string name) {
	fprintf(out_fp, "4.1.��ǰ ���� �˻�\n> ");
	for (int i = 0; i < productNum; i++) {
		//cout << productList[i]->getName();
		if (productList[i]->getName() == name) {
			productList[i]->getProductDetailWithSeller();
			this->nowSearchProduct = i;
			return i;
		}
	}
	// ��ǰ�� ã�� ���� ��� -1 ��ȯ
	return -1;
}

// Function : BuyProduct
// Description: BuyProduct class�� �������̴�.
// Created: 2022/5/31 02:40
// Author: �̴ټ�
BuyProduct::BuyProduct(int nowProductId) {
	this->buyProductProcess(nowProductId);
	string productName = productList[nowProductId]->getName();
	string sellerName = productList[nowProductId]->getSellerName();
	fprintf(out_fp, "4.2. ��ǰ ����\n> ");
	fprintf(out_fp, "%s %s\n\n", sellerName.c_str(), productName.c_str());
}

// Function : buyProductProcess
// Description: ������ �����ϰ� �̿� ���� ��� ������� �ش�. 
// Created: 2022/5/31 02:40
// Author: �̴ټ�
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
// Description: �α����� ������ ���� ������ ��ȸ�Ѵ�. 
// Created: 2022/5/31 02:40
// Author: �̴ټ�
void ShowPurchasedHistory::inquiryProductList() {
	Member *nowUser = member_list->activeMember;
	PurchasedProductCollection* tmpCollection = nowUser->getPurchasedProductCollection();
	int myPurchasedCount = tmpCollection->getPurchasedCount();
	int tmpPid = -1;
	fprintf(out_fp, "4.3. ��ǰ ���� ���� ��ȸ\n> ");
	for (int i = 0; i < myPurchasedCount; i++) {
		tmpPid = tmpCollection->getPurchasedProductId(i);
		int inquireProductId = tmpPid;
		//product
		productList[tmpPid]->getProductDetailWithSeller();
	}
}

// Function : scoreProduct
// Description: ���� ������ �򰡸� ���� ������ �޴´�. 
// Created: 2022/5/31 02:40
// Author: �̴ټ�
int ScoreUI::scoreProduct() {
	int score;
	fscanf(in_fp, "%d", &score);
	return score;
}
// Function :selectName
// Description: ���� ������ �򰡸� ���� ��ǰ�� ������ �޴´�. 
// Created: 2022/5/31 02:40
// Author: �̴ټ�
string ScoreUI::selectName() {
	char tmp[100];
	fscanf(in_fp, "%s", &tmp);
	string name = string(tmp);
	return name;
}

// Function: Score
// Description: Score class�� �������̴�. 
// Created: 2022/5/31 02:40
// Author: �̴ټ�
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
	fprintf(out_fp, "4.4. ��ǰ ���Ÿ����� ��\n> ");
	fprintf(out_fp, "%s %s %d \n\n", companyName.c_str(), pName.c_str(), inScore);
}

// Function: addScore
// Description: �Է��� ������ �����Ѵ�. 
// Created: 2022/5/31 02:40
// Author: �̴ټ�
void Score::addScore(int nowProductId, int score) {
	Member *nowUser = member_list->activeMember;
	nowUser->getPurchasedProductCollection()->addProductScore(nowProductId, score);
	productList[nowProductId]->addScore(score);
};
