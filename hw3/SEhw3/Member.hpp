//
//  Member.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/01.
//

#ifndef Member_hpp
#define Member_hpp

#include <stdio.h>

// class : Member
// Descrpition: 멤버를 정의한 클래스 입니다.
class Member{
private:
    char name[MAX_STRING], ssn[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
    string ID;
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
};







#endif /* Member_hpp */
