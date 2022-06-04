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

// 제품 메모리 저장소
int productNum = 0;
vector<Product*> productList;

// 변수 선언
FILE* in_fp, *out_fp;

// Member 리스트 관리
MemberCollection* member_list = new MemberCollection;

// 현재 고객의 product collection
ProductCollection* now_product_collection;



void doTask();

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	doTask();
	return 0;
}

void doTask() {
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	int nowSearchProduct = 0;

	while (!is_program_exit) {
		// 입력파일에서 메뉴 숫자 2개를 읽기
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // 1.1 회원가입
			{
				fprintf(out_fp, "1.1. 회원가입\n> ");
				Registration* psc0 = new Registration();
				break;
			}
			case 2: // 1.2 회원탈퇴
			{
				fprintf(out_fp, "1.2. 회원탈퇴\n> ");
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
			case 1: // 2.1 로그인
			{
				fprintf(out_fp, "2.1. 로그인\n> ");
				LogOn* psc0 = new LogOn();
				now_product_collection = member_list->activeMember->getProductCollection();
				break;
			}
			case 2: // 2.2 로그아웃
			{
				fprintf(out_fp, "2.2. 로그아웃\n> ");
				LogOut* psc0 = new LogOut();
				break;
			}
			}
			break;
		}

		case 3:
		{
			switch (menu_level_2) {
			case 1: // 3.1 판매 의류 등록 부분
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
			case 2: // 3.2 등록 상품 조회 부분
			{
				GetProductsUI getProductsUi;
				getProductsUi.getProductList();
				break;
			}
			case 3: // 3.3 판매 완료 상품 조회 부분
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
			switch (menu_level_2) {
			case 1:
			{
				//상품 정보 검색
				SearchProduct search;
				nowSearchProduct = search.getNowSearchProduct();
				break;
			}
			case 2:
			{
				//상품 구매
				BuyProduct buy(nowSearchProduct);
				break;
			}
			case 3:
			{
				// 상품 구매 내역 조회
				ShowPurchasedHistory history;
				break;
			}
			case 4:
			{
				//상품 구매 만족도 평가
				Score score(nowSearchProduct);
				break;
			}

			}
			break;

		}// end case4

		case 5:
		{
			switch (menu_level_2) {
			case 1: // 5.1 판매 상품 통계 부분
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
			case 1:   // "6.1. 종료“ 메뉴 부분
			{
				// program_exit();
				fprintf(out_fp, "6.1. 종료\n");
				is_program_exit = 1;
				break;;
			}
			}
			break;
		}

		}
	}
}