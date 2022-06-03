#include <stdio.h>
#include "Member.h"
#include "Product.h"
#pragma once

//class: Score
//Description: 구매 만족도 평가를 담당하는 control class 입니다.

class ScoreUI{
private:
public:
    int scoreProduct(FILE *in_fp);
    void showInterface(FILE *out_fp, string companyName, string pName, int score);
};

class Score{
private:
    ScoreUI ui;
public:
    Score(int nowProductId ,FILE* in_fp, FILE *out_fp);
    void addScore(int nowProductId, int score);

};
