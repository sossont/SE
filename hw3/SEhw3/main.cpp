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

//control class HeaderFile
#include "SearchProduct.hpp""
using namespace std;

//쇼핑몰 상품 리스트
Product productList[100];
//쇼핑몰 상품 개수
int productNum = 0;

// class : Member
// Descrpition: 멤버를 정의한 클래스 입니다.
class Member{
private:
    char name[MAX_STRING], ssn[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
    PurchasedProductCollection myPurchaseList;
public:
    Member(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]);
    char* getId() {
            return id;
        }
    char* getPassword() {
        return password;
    }
    void addMyPurchase(int pid);
    PurchasedProductCollection  getPurchasedProductCollection() {
        return this -> myPurchaseList;
        
    }
};


// Member entity 관리 클래스 (MemberCollection:Member, 1:Many관계)
class MemberCollection {
    public:
        Member* activeMember{ 0 }; //현재로그인된 유저 표시
        //vector를 이용하여 생성된 Member 객채들을 관리합니다. (처음에 private로 했는데 다른분들 접근을 고려하여 public으로 수정하였습니다.)
        vector<Member*> ownedMember;
        vector<Member*>::iterator member_iterator; //반복자 선언
        //새로운 회원가입 요청이 들어온 경우 유저의 아이디가 존재하지 않는 경우만 회원가입을 할 수 있게 return true로 반환합니다.
        bool verifyNewMember(char id_[MAX_STRING]) {
            // MemberCollection의 리스트가 0인 경우는 가입된 Member가 없으므로 바로 return true를 해줍니다.
            if (ownedMember.size() > 0) {
                // MemberCollection이 가지고 있는 Member들을 순서대로 확인해가면서 요청된 id와 동일한 id가 발견되지 않은 경우만 return true로 반환합니다.
                for (auto member : ownedMember) {
                    if (strcmp((member)->getId(), id_) == 0) {
                        return false;
                    }
                }
            }
            return true;
        }
        void addMembertoCollection (Member* new_user){
            ownedMember.push_back(new_user);
        }
        //로그인
        bool verifyMember(char id_[MAX_STRING], char password_[MAX_STRING]) {
            // MemberCollection의 리스트가 0인 경우는 가입된 Member가 없으므로 바로 return true를 해줍니다.
            if (ownedMember.size() > 0) {
                // MemberCollection이 가지고 있는 Member들을 순서대로 확인해가면서 요청된 id와 동일한 id가 발견되지 않은 경우만 return true로 반환합니다.
                for (auto member : ownedMember) {
                    if (strcmp((member)->getId(), id_) == 0 && strcmp((member)->getPassword(), password_) == 0) {
                        makeMemberActive(member);
                        return true;
                    }
                }
            }
            return false;
        }
        // 로그인한 유저를 가리키도록 한다.
        void makeMemberActive(Member* pcr) {
            activeMember = pcr;
        }
};
static MemberCollection* member_list = new MemberCollection;

Member::Member(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]) {
    strcpy(name, name_);
    strcpy(ssn, ssn_);
    strcpy(id, id_);
    strcpy(password, password_);
    member_list -> addMembertoCollection(this);
}


// DB 및 외부저장 장치에 연결이 되어있지 않으므로 전역함수로 멤버를 MemberCollection 클래스를 new로 생성해 Member 객체를 관리한다. (중복 가입 확인 및 로그인 확인)

//class : BuyProduct
//Description: 상품 구매를 담당하는 control class 입니다.
class BuyProduct{
private:
public:
    void buyProductProcess(int productId);
};

void BuyProduct::buyProductProcess(int productId){
    //재고가 하나 이상일 때 구매
    if (productList[productId].getStockCount() >0 ){
        productList[productId].changeProductAmount();
    }
    else{
        return ;
    }
    //구매 완료 후 구매한 상품 목록에 추가
    //구매자 본인 정보 받아옴
    Member *nowUser = member_list -> activeMember;
    nowUser ->getPurchasedProductCollection().addNewProduct(productId);
}

int inquireProductId = -1;

class ShowPurchasedHistoryUI{
private:
public:
    ShowPurchasedHistory();
    
    
};


//class:ShowPurchasedHistory
// Descrtiption: 구매내역 조회를 담당하는 control class입니다.
class ShowPurchasedHistory{
private:
    ShowPurchasedHistoryUI ui;
public:
    ShowPurchasedHistory(){
        
    }
    void inquiryProductList();
    
};




void ShowPurchasedHistory::inquiryProductList(){
    Member *nowUser = member_list -> activeMember;
    int myPurchasedCount = nowUser -> getPurchasedProductCollection().getPurchasedCount();
    int tmpPid = -1;
    for(int i =0; i< myPurchasedCount; i++){
        
        tmpPid = nowUser -> getPurchasedProductCollection().getPurchasedProductId(i);
        inquireProductId = tmpPid;
        //product 
        productList[tmpPid].getProductDetail();
        
    }
}




//class: Score
//Description: 구매 만족도 평가를 담당하는 control class 입니다.
class Score{
private:
public:
    void addScore(int score);
    
};


void Score::addScore(int score){
    //User의 구매 목록에 User가 매긴 별점을 저장한다.
    Member *nowUser = member_list -> activeMember;
    nowUser->getPurchasedProductCollection().addProductScore(inquireProductId,score);
    
    //Product의 객체에 새롭게 추가한 score값 저장.
    productList[inquireProductId].addScore(score);
    
    
};

class ScoreUI{
private:
public:
    
    
    
    
};

//class: InOut
//
class InOut{
private:
    FILE* in_fp, *out_fp;
public:
    InOut(){
        this -> in_fp = fopen(INPUT_FILE_NAME, "r+");
        this -> out_fp = fopen(OUTPUT_FILE_NAME, "w+");
    }
    void doTask();
    //case 1
    void join();
    //case 4
    int searchProduct(string name);
    void showPurchase();
    void scoreProduct(int score);
    void buyProduct(int productId);
    //case 6
    void program_exit();
    
};


void InOut::doTask(){
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    int nowSearchProduct = -1;
    while(!is_program_exit){
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(this-> in_fp, "%d %d ", &menu_level_1, &menu_level_2);
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
            char* out;
            switch(menu_level_2){
                case 1:
                {
                    //상품 정보 검색
                    char tmp[100];
                    fscanf(in_fp, "%s", tmp);
                    string name(tmp);
                    nowSearchProduct = searchProduct(name);
                    out = "4.1. 상품 정보 검색\n";
                    fprintf(out_fp, "%s", out);
                    break;
                }
                case 2:
                {
                    //상품 구매
                    buyProduct(nowSearchProduct);
                    out ="4.2. 상품 구매\n";
                    fprintf(out_fp, "%s", out);
                    break;
                }
                case 3:
                {
                    // 상품 구매 내역 조회
                    showPurchase();
                    out ="상품 구매 내역 조회\n";
                    fprintf(out_fp, "%s", out);
                    break;
                }
                case 4:
                {
                    //상품 구매 만족도 평가
                    int score;
                    fscanf(in_fp, "%d", &score);
                        out ="상품 구매만족도 평가\n";
                        scoreProduct(score);
                        fprintf(out_fp, "%s", out);
                        break;
                }
                    
            }
            
        }// end case4
        case 7:
        {
            switch(menu_level_2){
              case 1:   // "6.1. 종료“ 메뉴 부분
              {
                program_exit();
                is_program_exit = 1;
                break;;
              }
            }

       } //end case7

        }// end switch case
    }//end while
    return;
}//end do task


int BoundaryClass::searchProduct(string name){
    int productId =-1;
    SearchProduct controlClass;
    productId = controlClass.showProduct(name);
    return productId;
}

void BoundaryClass::buyProduct(int productId){
    BuyProduct controlClass;
    controlClass.buyProductProcess(productId);
    return ;
    
}

void BoundaryClass::showPurchase(){
    
    
}

void BoundaryClass::scoreProduct(int score){
    
}


void BoundaryClass::program_exit(){
    fprintf(out_fp, "%s", "종료");
    
}

int main(){
    BoundaryClass interface;
    interface.doTask();
}
