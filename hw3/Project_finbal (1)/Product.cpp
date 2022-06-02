#include "Product.h"

// Main �Լ����� ����ϴ� ������ �����ؼ� ����ϱ� ����
extern int productNum;
extern Product productList[100];
extern FILE* in_fp, *out_fp;
extern ProductCollection now_product_collection;

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
// Description: ��ǰ �� ������ ����ϴ� �Լ�.
// Created: 2022/5/31 18:00
// Author: ��ȯ��
void Product::getProductDetail() {
	fprintf(out_fp, "%s %s %d %d\n\n", this->productName.c_str(), this->companyName.c_str(), this->price, this->stockCount);
	// cout << this->productName << " " << this->companyName << " " << this->price << " " << this->stockCount << endl;
}

void Product::getProductDetailWithSeller() {
	int sellCount = this->count - this->stockCount; // ���� �Ǹŷ� = �� ���� - ���� ����
	int totalPrice = this->price * sellCount;
	double averageScore = 0;  // ���� �Ǹŷ��� 0���̸� score �� 0�� ��
	if (sellCount != 0)
	{
		averageScore = double(this->score) / double(sellCount); // ��� ���Ÿ����� = �� ������ / �Ǹ� ����
	}
	fprintf(out_fp, "%s %s %s %d %d %f\n\n", this->sellerID.c_str(), this->productName.c_str(), this->companyName.c_str(), this->price, this->stockCount, averageScore);
}

// Function : getSoldOutProductDetail
// Description: �Ǹ� �Ϸ�� ��ǰ ��ȸ �ϴ� �Լ�
// Created: 2022/5/31 18:00
// Author: ��ȯ��
void Product::getSoldOutProductDetail() {
	// stockCount �� 0�� �ƴϸ� �Ǹ� �Ϸ�� ��ǰ�� �ƴϴ�.

	if (this->stockCount != 0) {
		return;
	}
	fprintf(out_fp, "%s %s %d %d %d\n\n", this->productName.c_str(), this->companyName.c_str(), this->price, this->count, this->score);
}

// Function : getAllProductStats
// Description: �Ǹ� ��ǰ ��� ����ϴ� �Լ�.
// Created: 2022/5/31 18:00
// Author: ��ȯ��
void Product::getProductStat() {
	int sellCount = this->count - this->stockCount; // ���� �Ǹŷ� = �� ���� - ���� ����
	int totalPrice = this->price * sellCount;
	double averageScore = 0;    // ���� �Ǹŷ��� 0���̸� score �� 0�� ��
	if (sellCount != 0)
	{
		averageScore = double(this->score) / double(sellCount); // ��� ���Ÿ����� = �� ������ / �Ǹ� ����
	}
	fprintf(out_fp, "%s %d %.1f\n", this->productName.c_str(), totalPrice, averageScore);
}

void Product::addScore(int score) {
	this->score += score;
}

void Product::changeProductAmount() {

	this->stockCount = this->stockCount - 1;
}

// Function : getAllProductStats
// Description: �÷��� ��ȸ ���鼭, �Ǹ� ��� ��� �Ѵ�.
// Created: 2022/5/31 18:00
// Author: ��ȯ��
void ProductCollection::getAllProductStats() {
	for (auto product : ownedProduct) {
		product.getProductStat();
	}
}

// Function : getAllProducts
// Description: ��� ��ǰ ��ȸ�ϴ� �Լ���, �÷��� ��ȸ�� ���鼭 ��ǰ ���� ����Ѵ�.
// Created: 2022/5/31 18:00
// Author: ��ȯ��
void ProductCollection::getAllProducts() {
	for (auto product : ownedProduct) {
		product.getProductDetail();
	}
}

// Function : getSoldOutProducts
// Description: �÷��� ��ȸ ���� �Ǹ� �Ϸ�� ��ǰ �� ���� ���
// Created: 2022/5/31 18:00
// Author: ��ȯ��
void ProductCollection::getSoldOutProducts() {
	for (auto product : ownedProduct) {
		product.getSoldOutProductDetail();
	}
}

// Function : addNewProduct
// Description: ���ο� ��ǰ �߰��ϴ� �Լ���, ���ο� ��ǰ ������ �÷��ǿ� �߰��Ѵ�. ��ü ��ǰ�� �߰��ϱ� ���� product ��ȯ
// Created: 2022/5/31 18:00
// Author: ��ȯ��

void ProductCollection::addNewProduct(string sellerID, string productName, string companyName, int price, int count) {
	Product product = *new Product(sellerID, productName, companyName, productNum, price, count);
	// ���� �迭�� �߰�
	product.getProductDetail();
	productList[productNum++] = product;
	this->ownedProduct.push_back(product);
}

void AddProductUI::addProduct(string sellerID, string productName, string companyName, int price, int count) {
	fprintf(out_fp, "3.1. �Ǹ� �Ƿ� ���\n");
	AddProduct addProduct;
	addProduct.addProduct(sellerID, productName, companyName, price, count);
}

void AddProduct::addProduct(string sellerID, string productName, string companyName, int price, int count) {
	// Member�� productCollection
	now_product_collection.addNewProduct(sellerID, productName, companyName, price, count);
}

// Function : calculateAllProductStats
// Description: Boundary Ŭ���� ����. ��踦 ���� control class �Լ� ȣ��.
// Created: 2022/6/2/13:20
// Author: ��ȯ��
void CalculateUI::calculateAllProductStats() {
	fprintf(out_fp, "5.1 �Ǹ� ��ǰ ���\n");
	Calculate calculate;
	calculate.calculateAllProductStats();
}

// Function : calculateAllProductStats
// Description: �÷��ǿ��� ��� ��ȸ �ϱ�
// Created: 2022/6/2/13:20
// Author: ��ȯ��
void Calculate::calculateAllProductStats() {
	now_product_collection.getAllProductStats();
}

// Function : getProductList
// Description: ��� ��ǰ ��ȸ�� ���� control class �Լ� ȣ��
// Created: 2022/6/2/13:20
// Author: ��ȯ��
void GetProductsUI::getProductList() {
	GetProducts getProducts;
	getProducts.getProductList();
}

// Function : getProductList
// Description: �÷��ǿ��� ��� ��ǰ �� ��ȸ.
// Created: 2022/6/2/13:20
// Author: ��ȯ��
void GetProducts::getProductList() {
	fprintf(out_fp, "3.2. ��� ��ǰ ��ȸ\n");
	now_product_collection.getAllProducts();
}

// Function : getSoldOutProducts
// Description: �Ǹ� �Ϸ� ��ǰ ��ȸ�� ���� control class �Լ� ȣ��
// Created: 2022/6/2/13:20
// Author: ��ȯ��
void GetSoldOutProductUI::getSoldOutProducts() {
	GetSoldOutProduct getSoldOutProduct;
	getSoldOutProduct.getSoldOutProducts();
}

// Function : getSoldOutProducts
// Description: �÷��ǿ��� �Ǹ� �Ϸ�� ��ǰ ȣ��
// Created: 2022/6/2/13:20
// Author: ��ȯ��
void GetSoldOutProduct::getSoldOutProducts() {
	fprintf(out_fp, "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n");
	now_product_collection.getSoldOutProducts();
}

