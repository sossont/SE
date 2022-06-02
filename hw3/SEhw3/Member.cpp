//
//  Member.cpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/01.
//

#include "Member.hpp"
#define MAX_STRING 32

extern MemberCollection* member_list;

Member::Member(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]) {
    strcpy(name, name_);
    strcpy(ssn, ssn_);
    strcpy(id, id_);
    strcpy(password, password_);
    member_list -> addMembertoCollection(this);
}

