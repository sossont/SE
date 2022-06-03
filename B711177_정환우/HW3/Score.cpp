//
//  Score.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#include "Score.h"
extern Product productList[100];
extern int productNum;
extern MemberCollection* member_list;

void ScoreUI::showInterface(FILE *out_fp, string companyName, string pName, int score){
    char *out = "상품 구매만족도 평가\n";
    fprintf(out_fp, "%s", out);

    fprintf(out_fp, "%s %s %d", companyName.c_str(),pName.c_str() ,score);
    return;
}


int ScoreUI::scoreProduct(FILE *in_fp){
    int score;
    fscanf(in_fp, "%d", &score);
    return score;
}


//Score class의 함수 구현
Score::Score(int nowProductId, FILE *in_fp, FILE *out_fp){
    int inScore = ui.scoreProduct(in_fp);
    this -> addScore(nowProductId,inScore);
    string pName = productList[nowProductId].getName();
    string companyName = productList[nowProductId].getCompanyName();
    ui.showInterface(out_fp, pName, companyName, inScore );
}

void Score::addScore(int nowProductId, int score){
    //User의 구매 목록에 User가 매긴 별점을 저장한다.
    Member *nowUser = member_list->activeMember;
    nowUser->getPurchasedProductCollection().addProductScore(nowProductId,score);

    //Product의 객체에 새롭게 추가한 score값 저장.
    productList[nowProductId].addScore(score);

};