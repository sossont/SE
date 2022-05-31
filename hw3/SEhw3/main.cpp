#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;


//class: Product
//Descrpition : this is class for product
class Product{
private:
    string name;
    string companyName;
    int productId;
    int price;  // 가격
    int stockCount; // 현재 수량
    int count;  // 총 수량 = 판매 완료시 판매된 수량
    int score = 0;  // 구매 만족도의 합. 총 구매 만족도 / (총 수량 - 현재 수량) = 현재 구매 만족도

public:
    Product(string productName="", string companyName="",int productId =-1, int price=0, int count=0){
        this->name = productName;
        this->companyName = companyName;
        this -> productId = productId;
        this->price = price;
        this->count = count;
        this->stockCount = count;
    }
    void getProductDetail(); // 상품 디테일 정보 가져오는 함수. 상품 정보 출력해준다.
    void getSoldOutProductDetail();
    void getProductStat();
    void changeProductAmount();
    //void searchProduct(string productName);
    void buyProduct();
    string getName(){return this->name; }
    int getStockCount(){ return this -> stockCount; }
};

//쇼핑몰 상품 리스트
Product productList[100];
//쇼핑몰 상품 개수
int productNum = 0;


void Product::getProductStat() {
    int sellCount = this->count - this->stockCount; // 현재 판매량 = 총 수량 - 현재 수량
    int totalPrice = this->price * sellCount;
    int averageScore = this->score / sellCount; // 평균 구매만족도 = 총 만족도 / 판매 수량
    cout << this->name << " " << totalPrice << " " << averageScore << endl;
}
//Function
//Descrpition: 상품의 정보를 출력해준다.
void Product::getProductDetail() {
    cout << this->name << " " << this->companyName << " " << this->price << " " << this->stockCount << endl;
}

void Product::getSoldOutProductDetail() {
    // stockCount 가 0이 아니면 판매 완료된 상품이 아니다.

    if (this->stockCount != 0){
        return;
    }

    cout << this->name << " " << this->companyName << " " << this -> price << " " << this->count << " " << this->score << endl;
}

void Product::changeProductAmount(){
    this -> stockCount = this->stockCount -1;
}

//class ProductCollection
class ProductCollection{

private:
    vector<Product> ownedProduct;

public:
    void addNewProduct(string productName, string companyName, int price, int count); // 3.1 판매 상품 등록. 상품명, 제작회사명, 가격, 수량
    void getAllProduct(); // 3.2 등록 상품 조회. 모든 ownedProduct 순회하면서 상품명, 제작회사명, 가격, 수량 출력하면 된다.
    void getSoldOutProduct();   // 3.3 판매 완료 상품 조회
    void getProductStat();  // 5.1 판매 상품 통계 출력하는 함수.
};


void ProductCollection::getProductStat() {
    for (auto product : ownedProduct) {
        product.getProductStat();
    }
}

// 모든 상품 순회해서 조회하면 된다.
void ProductCollection::getAllProduct() {
    for (auto product : ownedProduct) {
        product.getProductDetail();
    }
}


void ProductCollection::getSoldOutProduct() {
    for (auto product : ownedProduct) {
        product.getSoldOutProductDetail();
    }
}

// 상품 정보 추가
void ProductCollection::addNewProduct(string productName, string companyName, int price, int count) {
    Product product = *new Product(productName, companyName, price, count);
    ownedProduct.push_back(product);
}



class PurchasedProduct{
private:
    int productId;
    int score;
public:
    PurchasedProduct(int id){
        this->productId = id;
        score = -1;
    }
    bool isPurchased();
    bool isRate();
    int getPurchasedProduct();
};


bool PurchasedProduct::isRate(){
    if(this->score == -1){
        return false;
    }
    else
        return true;
}



class PurchasedProductCollection{
private:
    PurchasedProduct *PurchasedList;
public:
    PurchasedProduct* findFirst();
    PurchasedProduct*  getNext();
    int addNewProduct(int productId);
    void AddProductScore(int score);
};

//class: SearchProduct
//Descrption 상품 검색을 담당하는 control class 클래스 입니다.
class SearchProduct{
private:
public:
    int showProduct(string name);
};


int SearchProduct::showProduct(string name){
    for(int i=0; i < productNum; i++){
        if(productList[i].getName() == name){
            productList[i].getProductDetail();
            return i;
        }
    }
    // 상품을 찾지 못한 경우 -1 반환
    return -1;
}

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
    
    
    
}


//class: BoundaryClass
//
class BoundaryClass{
private:
    FILE* in_fp, *out_fp;
public:
    BoundaryClass(){
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


void BoundaryClass::doTask(){
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
