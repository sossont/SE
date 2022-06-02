//
//  Member.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/01.
//

#ifndef Member_hpp
#define Member_hpp

#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include "PurchasedProductCollection.hpp"

#define MAX_STRING 32
using namespace std;

//class : Member
//Descrpition: 멤버를 정의한 클래스 입니다.
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

extern MemberCollection* member_list;


#endif /* Member_hpp */
