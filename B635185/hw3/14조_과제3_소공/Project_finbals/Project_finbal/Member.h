#pragma once
#define MAX_STRING 32
#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include "Product.h"
#include "Buy.h"

using namespace std;

// Class : Member
// Description: 회원 정보 저장하는 클래스
// Created: 2022/6/01 15:00
// Author: 서동우

class Member {
private:
	char name[MAX_STRING]; // 회원의 이름
	char ssn[MAX_STRING]; // 회원의 주민번호
	char id[MAX_STRING]; // 회원의 아이디
	char password[MAX_STRING]; // 회원의 비밀번호
	PurchasedProductCollection myPurchaseList; // 회원의 구매내역
	ProductCollection MyproductCollection; // 회원의 등록 상품내역
public:
	//생성자
	Member(char name[MAX_STRING], char ssn[MAX_STRING], char id[MAX_STRING], char password[MAX_STRING]);
	char* getId();
	char* getPassword();
	ProductCollection *getProductCollection();
	PurchasedProductCollection* getPurchasedProductCollection();
};

// Class : MemberCollection
// Description: 가입한 회원들을 저장하는 컬렉션 클래스
// Created: 2022/6/01 15:00
// Author: 서동우

class MemberCollection {
public:
	Member* activeMember{ 0 }; // 현재로그인된 유저 (쿠키역할)
	vector<Member*> ownedMember; // 벡터로 회원 리스트 관리
	vector<Member*>::iterator member_iterator;

	bool verifyNewMember(char id[MAX_STRING]);
	void addMemberToCollection(Member* new_user);

	bool verifyMember(char id[MAX_STRING], char password[MAX_STRING]);
	void makeMemberActive(Member* pcr);
	void removeMemberFromCollection();
	void deactivateMember();

};

// Class : Registration 
// Description: control class for member registration
// Created: 2022/6/01 15:00
// Author: 서동우

class Registration {
public:
	Registration();
	bool addNewMember(char name[MAX_STRING], char ssn[MAX_STRING], char id[MAX_STRING], char password[MAX_STRING]);
};

// Class : Registration 
// Description: boundary class for member registration
// Created: 2022/6/01 15:00
// Author: 서동우

class RegistrationUI {
private:
	//멤버변수
	char user_type[MAX_STRING], name[MAX_STRING], ssn[MAX_STRING], address[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
public:
	RegistrationUI(Registration* pc);
	void submitBasicInformation();
	void showInformation();
};

// Class : Registration 
// Description: control class for member log on
// Created: 2022/6/01 15:00
// Author: 서동우

class LogOn {
public:
	LogOn();
	bool requestLogOn(char id[MAX_STRING], char password[MAX_STRING]);
};

// Class : Registration 
// Description: boundary class for member log on
// Created: 2022/6/01 15:00
// Author: 서동우

class LogOnUI {
private:
	char id[MAX_STRING]; 
	char password[MAX_STRING];

public:
	LogOnUI(LogOn* pc);
	void userLogOn();
	void showInformation();

};

// Class : Registration 
// Description: control class for member log out
// Created: 2022/6/01 15:00
// Author: 서동우

class LogOut {
public:
	LogOut();
	void requestLogOut();
};

// Class : Registration 
// Description: boundary class for member log out
// Created: 2022/6/01 15:00
// Author: 서동우

class LogOutUI {
private:
	char id[MAX_STRING];
public:
	LogOutUI(LogOut* pc);
	void userLogOut();
	void showInformation();
};

// Class : Registration 
// Description: control class for member withdraw
// Created: 2022/6/01 15:00
// Author: 서동우

class Withdraw {
public:
	Withdraw();
	void  withdrawMember();
};

// Class : Registration 
// Description: boundary class for member withdraw
// Created: 2022/6/01 15:00
// Author: 서동우

class WithdrawUI {
private:
	char id[MAX_STRING];

public:
	WithdrawUI(Withdraw* pc);
	void requestWithdraw();
	void showInformation();
};
