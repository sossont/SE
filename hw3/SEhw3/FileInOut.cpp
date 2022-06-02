//
//  FileInOut.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "FileInOut.hpp"


void FileInOut::doTask(){
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    
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
