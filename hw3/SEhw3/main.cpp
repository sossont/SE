#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

//Header File
#include "Product.hpp"
#include "ProductCollection.hpp"
#include "PurchasedProduct.hpp"
#include "PurchasedProductCollection.hpp"
#include "FileInOut.hpp"

//control class HeaderFile
#include "SearchProduct.hpp"
#include "BuyProduct.hpp"
#include "ShowPurchaseHistory.hpp"
#include "Score.hpp"
using namespace std;

//쇼핑몰 상품 리스트
Product productList[100];
//쇼핑몰 상품 개수
int productNum = 0;
//멤버 저장하기 위한 변수
MemberCollection* member_list = new MemberCollection;

int inquireProductId = -1;

FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
int nowSearchProduct = -1;
int main(){
    FileInOut f;
    f.doTask();    
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    int nowSearchProduct = -1;
    while(!is_program_exit){
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        // 메뉴 구분 및 해당 연산 수행
        switch(menu_level_1){
        case 1:
        {
            switch(menu_level_2){
              case 1:   // "1.1. 회원가입“ 메뉴 부분
              {
              // join() 함수에서 해당 기능 수행
                //join();
                break;
              }
              case 2:
              {
                break;
              }
            }
        }//end case1
        case 4:
        {
            switch(menu_level_2){
                case 1:
                {
                    //상품 정보 검색
                    SearchProduct search(in_fp, out_fp);
                    nowSearchProduct =search.getNowSearchProduct();
                    break;
                }
                case 2:
                {
                    //상품 구매
                    BuyProduct buy(nowSearchProduct,out_fp);
                    break;
                }
                case 3:
                {
                    // 상품 구매 내역 조회
                    ShowPurchasedHistory history(out_fp);
                    break;
                }
                case 4:
                {
                    //상품 구매 만족도 평가
                    Score score(nowSearchProduct,in_fp, out_fp);
                        break;
                }
                    
            }
            
        }// end case4
        case 7:
        {
            switch(menu_level_2){
              case 1:   // "6.1. 종료“ 메뉴 부분
              {
                //program_exit();
                is_program_exit = 1;
                break;;
              }
            }

       } //end case7

        }// end switch case
    }//end while
    return 0;
}
