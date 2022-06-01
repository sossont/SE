#include "Product.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;

// 제품 메모리 저장소
int productNum = 0;
Product productList[100];
// 변수 선언
FILE* in_fp, *out_fp;

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
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
            case 1: {
                switch (menu_level_2) {
                    case 1:   // "1.1. 회원가입“ 메뉴 부분
                    {
                        // join() 함수에서 해당 기능 수행

                        break;
                    }
                    case 2: {
                        break;
                    }
                }
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
                        addProductUi.addProduct(productName,companyName,price,count);
                    }
                    case 2: // 3.2 등록 상품 조회 부분
                    {
                        GetProductsUI getProductsUi;
                        getProductsUi.getProducts();
                    }
                    case 3: // 3.3 판매 완료 상품 조회 부분
                    {
                        GetSoldOutProductUI getSoldOutProductUi;
                        getSoldOutProductUi.getSoldOutProduct();
                    }
                }
            }
            case 7: {
                switch (menu_level_2) {
                    case 1:   // "6.1. 종료“ 메뉴 부분
                    {
                        // program_exit();
                        is_program_exit = 1;
                        break;;
                    }
                }
            }

        }
    }
}

