#ifndef UNTITLED2_PRODUCT_H
#define UNTITLED2_PRODUCT_H
#define MAX_STRING 32
#include <vector>
#include <string>
#include <iostream>
#pragma once

using namespace std;

// Class : Product
// Description: ��ǰ ���� �����ϴ� Ŭ����
// Created: 2022/5/31 18:00
// Author: ��ȯ��

class Product {
private:
	string sellerID;
	string productName;
	string companyName;
	int productId;
	int price;  // ����
	int stockCount; // ���� ����
	int count;  // �� ���� = �Ǹ� �Ϸ�� �Ǹŵ� ����
	int score = 0;  // ���� �������� ��. �� ���� ������ / (�� ���� - ���� ����) = ���� ���� ������

public:
	Product() = default;
	Product(string sellerID, string productName, string companyName, int productId, int price, int count);
	void getProductDetail(); // ��ǰ ������ ���� �������� �Լ�. ��ǰ ���� ������ش�.
	void getSoldOutProductDetail();
	void getProductStat();
	void changeProductAmount();
	//void searchProduct(string productName);

	string getName() { return this->productName; }
	int getStockCount() { return this->stockCount; }
	void addScore(int score);
	string getSellerName() { return this->sellerID; }
	void getProductDetailWithSeller();

};

// Class : ProductCollection
// Description : �Ǹ��ڰ� �Ǹ��� ��ǰ���� �����س��� �÷���
// Created : 2022/5/31 18:00
// Author : ��ȯ��
class ProductCollection {
private:
	vector<Product> ownedProduct;

public:
	ProductCollection() = default;
	void addNewProduct(string
		sellerID, string productName, string companyName, int price, int count); // 3.1 �Ǹ� ��ǰ ���. ��ǰ��, ����ȸ���, ����, ����
	void getAllProducts(); // 3.2 ��� ��ǰ ��ȸ. ��� ownedProduct ��ȸ�ϸ鼭 ��ǰ��, ����ȸ���, ����, ���� ����ϸ� �ȴ�.
	void getSoldOutProducts();   // 3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
	void getAllProductStats();  // 5.1 �Ǹ� ��ǰ ��� ����ϴ� �Լ�.
};

// Class : AddProductUI
// Description : boundary class for add product
// Created : 2022/06/02 01:18
// Author : ��ȯ��

class AddProductUI {
public:
	AddProductUI() = default;
	void addProduct(string sellerID, string productName, string companyName, int price, int count);
};

// Class : AddProduct
// Description : control class for add product
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class AddProduct {
public:
	AddProduct() = default;
	void addProduct(string sellerID, string productName, string companyName, int price, int count);
};

// Class : CalculateUI
// Description : boundary class for getting all products stats
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class CalculateUI {
public:
	CalculateUI() = default;
	void calculateAllProductStats();
};

// Class : Calculate
// Description : control class for getting all products stats
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class Calculate {
public:
	Calculate() = default;
	void calculateAllProductStats();
};

// Class : GetProductsUI
// Description : boundary class for getting product list
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class GetProductsUI {
public:
	GetProductsUI() = default;
	void getProductList();
};

// Class : GetProducts
// Description : control class for getting product list
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class GetProducts {
public:
	GetProducts() = default;
	void getProductList();
};

// Class : GetSoldOutProductUI{
// Description : boundary class for getting sold out product list
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class GetSoldOutProductUI {
public:
	GetSoldOutProductUI() = default;
	void getSoldOutProducts();
};

// Class : GetSoldOutProduct
// Description : control class for getting sold out product list
// Created : 2022/06/02 01:18
// Author : ��ȯ��
class GetSoldOutProduct {
public:
	GetSoldOutProduct() = default;
	void getSoldOutProducts();
};
#endif