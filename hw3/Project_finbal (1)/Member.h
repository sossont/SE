#pragma once
// Member Entity
#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include "Product.h"
#include "Buy.h"

using namespace std;

extern FILE* in_fp, *out_fp;
extern ProductCollection now_product_collection;
#define MAX_STRING 32

class Member {
private:
	//멤버변수: 이름, 주민번호, 아이디, 비번 (출력 예시에 나온 이름과 맞췄습니다.)
	char name[MAX_STRING], ssn[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
	PurchasedProductCollection myPurchaseList;
public:
	//생성자
	Member(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]);
	//생성된(회원가입한) 멤버의 id 반환
	char* getId();
	//로그인 추가
	char* getPassword();
	ProductCollection now_product_collection;

	//추가부분:
	PurchasedProductCollection getPurchasedProductCollection();
};

// Member entity 관리 클래스 (MemberCollection:Member, 1:Many관계)
class MemberCollection {
public:
	Member* activeMember{ 0 }; //현재로그인된 유저 표시

	//vector를 이용하여 생성된 Member 객채들을 관리합니다. (처음에 private로 했는데 다른분들 접근을 고려하여 public으로 수정하였습니다.)
	vector<Member*> ownedMember;
	vector<Member*>::iterator member_iterator; //반복자 선언
	//새로운 회원가입 요청이 들어온 경우 유저의 아이디가 존재하지 않는 경우만 회원가입을 할 수 있게 return true로 반환합니다.
	bool verifyNewMember(char id_[MAX_STRING]);
	void addMembertoCollection(Member* new_user);

	//로그인
	bool verifyMember(char id_[MAX_STRING], char password_[MAX_STRING]);
	// 로그인한 유저를 가리키도록 한다.
	void makeMemberActive(Member* pcr);
	// 편의를 위해 멤버 컬렉션에서 객체를 삭제하도록 변경
	void removeMember();
	void deactivateMember();

};

// DB 및 외부저장 장치에 연결이 되어있지 않으므로 전역함수로 멤버를 MemberCollection 클래스를 new로 생성해 Member 객체를 관리한다. (중복 가입 확인 및 로그인 확인)
class Registraion;
class RegistrationUI;

class Registration {
public:
	Registration();
	// 회원가입 UI 클래스에서 회원가입 요청이 들어올 경우 실행
	// 회원가입이 승인된 경우만 return true로 반환한다.
	bool addNewMember(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]);
};

class RegistrationUI {
private:
	//멤버변수
	char user_type[MAX_STRING], name[MAX_STRING], ssn[MAX_STRING], address[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
public:
	RegistrationUI(Registration* pc);
	// input.txt에서 입력받기
	void SubmitBasicInformation();
	// output.txt에 결과적기
	void ShowInformation();
};


class LogOn {
public:
	LogOn();
	bool requestLogOn(char id_[MAX_STRING], char password_[MAX_STRING]);
};

class LogOnUI {
private:
	//멤버변수
	char id[MAX_STRING], password[MAX_STRING];


public:
	LogOnUI(LogOn* pc);
	// input.txt에서 입력받기
	void userLogOn();
	// output.txt에 결과적기
	void ShowInformation();

};

// 로그아웃 use case
class LogOut;
class LogOutUI;

class LogOut {
public:
	LogOut();
	// 회원탈퇴는 로그인된 상태에서 한다고 가정하므로 무존건 성공한다. 따라서 void로 설정.
	void requestLogout();
};

class LogOutUI {
private:
	//멤버변수
	char id[MAX_STRING];
public:
	LogOutUI(LogOut* pc);
	// clickLogout() 실행시 로그인된 회원의 id를 가져온다고 가정(delete 하기 전에 보관용)
	void clickLogout();
	// output.txt에 결과적기
	void ShowInformation();
};


// 회원탈퇴 use case
class Withdraw;
class WithdrawUI;

class Withdraw {
public:
	Withdraw();
	// 회원탈퇴는 로그인된 상태에서 한다고 가정하므로 무존건 성공한다. 따라서 void로 설정.
	void  withdrawMember();
};

class WithdrawUI {
private:
	//멤버변수
	char id[MAX_STRING];


public:
	WithdrawUI(Withdraw* pc);
	// requestWithdraw() 실행시 로그인된 회원의 id를 가져온다고 가정(delete 하기 전에 보관용)
	void requestWithdraw();
	// output.txt에 결과적기
	void ShowInformation();

};
