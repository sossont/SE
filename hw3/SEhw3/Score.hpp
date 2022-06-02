//
//  Score.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>
#include "Member.hpp"
#include "Product.hpp"

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



#endif /* Score_hpp */
