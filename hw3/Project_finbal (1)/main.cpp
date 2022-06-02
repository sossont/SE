#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <stdio.h>
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Product.h"
#include "Buy.h"

using namespace std;

// ��ǰ �޸� �����
int productNum = 0;
Product productList[100];

// ���� ����
FILE* in_fp, *out_fp;

// Member ����Ʈ ����
MemberCollection* member_list = new MemberCollection;

// ���� ���� product collection
ProductCollection now_product_collection;


void doTask();

int main()
{
	// ���� ������� ���� �ʱ�ȭ
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	doTask();
	return 0;
}

void doTask() {
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	while (!is_program_exit) {
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		// �޴� ���� �� �ش� ���� ����
		cout << menu_level_1 << menu_level_2 << endl;
		switch (menu_level_1) {
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				fprintf(out_fp, "1.1. ȸ������\n> ");
				Registration* psc0 = new Registration();
				break;
			}
			case 2:
			{
				fprintf(out_fp, "1.2. ȸ��Ż��\n> ");
				Withdraw* psc0 = new Withdraw();
				break;
			}
			}
			break;
		}
		case 2:
		{

			switch (menu_level_2)
			{
			case 1:
			{
				fprintf(out_fp, "2.1. �α���\n> ");
				LogOn* psc0 = new LogOn();
				break;
			}
			case 2:
			{
				fprintf(out_fp, "2.2. �α׾ƿ�\n> ");
				LogOut* psc0 = new LogOut();
				break;
			}
			}
			break;
		}

		case 3:
		{
			switch (menu_level_2) {
			case 1: // 3.1 �Ǹ� �Ƿ� ��� �κ�
			{
				char tmp1[MAX_STRING];
				char tmp2[MAX_STRING];
				int price, count;
				fscanf(in_fp, "%s %s %d %d", tmp1, tmp2, &price, &count);
				string productName(tmp1);
				string companyName(tmp2);
				AddProductUI addProductUi;
				string sellerID = member_list->activeMember->getId();
				addProductUi.addProduct(sellerID, productName, companyName, price, count);
				break;
			}
			case 2: // 3.2 ��� ��ǰ ��ȸ �κ�
			{
				GetProductsUI getProductsUi;
				getProductsUi.getProductList();
				break;
			}
			case 3: // 3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ �κ�
			{
				GetSoldOutProductUI getSoldOutProductUi;
				getSoldOutProductUi.getSoldOutProducts();
				break;
			}
			}
			break;
		}
		case 4:
		{
			int nowSearchProduct = 0;
			switch (menu_level_2) {
			case 1:
			{
				//��ǰ ���� �˻�
				SearchProduct search;
				nowSearchProduct = search.getNowSearchProduct();
				break;
			}
			case 2:
			{
				//��ǰ ����
				BuyProduct buy(nowSearchProduct);
				break;
			}
			case 3:
			{
				// ��ǰ ���� ���� ��ȸ
				ShowPurchasedHistory history;
				break;
			}
			case 4:
			{
				//��ǰ ���� ������ ��
				Score score(nowSearchProduct);
				break;
			}

			}
			break;
			cout << "y";

		}// end case4

		case 5:
		{
			switch (menu_level_2) {
			case 1: // 5.1 �Ǹ� ��ǰ ��� �κ�
			{
				CalculateUI calculateUi;
				calculateUi.calculateAllProductStats();
				break;
			}
			}
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1:   // "6.1. ���ᡰ �޴� �κ�
			{
				// program_exit();
				fprintf(out_fp, "6.1. ����\n");
				is_program_exit = 1;
				break;;
			}
			}
			break;
		}

		}
	}
}