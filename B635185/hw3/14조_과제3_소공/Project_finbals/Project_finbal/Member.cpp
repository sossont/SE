#include "Member.h"

// Main 함수에서 사용하는 변수들 공유해서 사용하기 위함
extern FILE* in_fp, *out_fp;
extern MemberCollection* member_list;
extern ProductCollection* now_product_collection;

Member::Member(char name[MAX_STRING], char ssn[MAX_STRING], char id[MAX_STRING], char password[MAX_STRING]) {
	strcpy(this->name, name);
	strcpy(this->ssn, ssn);
	strcpy(this->id, id);
	strcpy(this->password, password);
	member_list->addMemberToCollection(this);
}

// Function : char* getId()
// Description: 회원의 id를 반환하는 함수.
// Return Value: member's id
// Created: 2022/6/02 18:00
// Author: 서동우

char*Member::getId() {
	return id;
}

// Function : char* getPassword()
// Description: 회원의 password를 반환하는 함수.
// Return Value: member's password
// Created: 2022/6/02 18:00
// Author: 서동우

char*Member::getPassword() {
	return password;
}

// Function : ProductCollection* getProductCollection()
// Description: 회원 product collection을 반환하는 함수
// Return Value: member's password
// Created: 2022/6/02 18:00
// Author: 서동우

ProductCollection* Member::getProductCollection() {
	return &this->MyproductCollection;
}

// Function : PurchasedProductCollection* getPurchasedProductCollection()
// Description: 회원 purchased prodduct collection(구매내역) 을 반환하는 함수
// Return Value: member's password
// Created: 2022/6/02 18:00
// Author: 서동우

PurchasedProductCollection* Member::getPurchasedProductCollection() {
	return &this->myPurchaseList;
}

// Function : bool verifyNewMember(char id[MAX_STRING])
// Description: 가입을 요청한 회원이 존재하는지 확인하는 하는 함수
// Parameter: char id[MAX_STRING] - 회원가입을 요청한 id
// Return Value: 회원가입 요청이 가능하면 true를 반환
// Created: 2022/6/02 18:00
// Author: 서동우

bool MemberCollection::verifyNewMember(char id[MAX_STRING]) {
	// MemberCollection의 리스트가 0인 경우는 가입된 Member가 없으므로 바로 return true를 해줍니다.
	if (ownedMember.size() > 0) {
		// MemberCollection이 가지고 있는 Member들을 순서대로 확인해가면서 요청된 id와 동일한 id가 발견되지 않은 경우만 return true로 반환합니다.
		for (auto member : ownedMember) {
			if (strcmp((member)->getId(), id) == 0) {
				return false;
			}
		}
	}
	return true;
}

// Function : addMemberToCollection(Member* new_user)
// Description: 새롭게 회원가입을 한 회원을 MemberCollection에 추가한다.
// Parameter: Member* new_user - 새롭게 회원가입을 한 Member
// Created: 2022/5/31 22:00
// Author: 서동우

void MemberCollection::addMemberToCollection(Member* new_user) {
	ownedMember.push_back(new_user);
}

// Function : bool verifyMember(char id[MAX_STRING], char password[MAX_STRING])
// Description: 로그인 요청한 회원이 회원가입을 하여 MemberCollection에 있는지 확인하는 함수
// Parameter: char id[MAX_STRING] - 로그인을 요청한 아이디, char password[MAX_STRING] - 로그인을 요청한 비밀번호
// Return Value: 로그인 가능하면(아이디와 비밀번호 일치) true를 반환
// Created: 2022/5/31 22:00
// Author: 서동우

bool MemberCollection::verifyMember(char id[MAX_STRING], char password[MAX_STRING]) {
	if (ownedMember.size() > 0) {
		for (auto member : ownedMember) {
			if (strcmp((member)->getId(), id) == 0 && strcmp((member)->getPassword(), password) == 0) {
				makeMemberActive(member);
				return true;
			}
		}
	}
	return false;
}

// Function : makeMemberActive(Member* pcr)
// Description: 로그인에 성공한 멤버를 현재 로그인한 회원으로 설정하는 함수 (브라우저의 쿠키 역할로 로그인후 기능 수행 가능)
// Parameter: Member* pcr - 현재 로그인한 회원
// Created: 2022/5/31 22:00
// Author: 서동우

void MemberCollection::makeMemberActive(Member* pcr) {
	activeMember = pcr;
}

// Function : removeMemberFromCollection()
// Description: 로그인한 회원이 회원탈퇴 요청시 회원을 Member Collection에서 삭제한 후, 로그아웃 상태로 만드는 함수
// Created: 2022/5/31 22:00
// Author: 서동우

void MemberCollection::removeMemberFromCollection() {
	delete activeMember;
	activeMember = NULL;
}

// Function : removeMemberFromCollection()
// Description: 로그인한 회원이 로그아웃을 요청시 로그인한 회원을 NULL로 변경한다.
// Created: 2022/5/31 22:00
// Author: 서동우

void MemberCollection::deactivateMember() {
	activeMember = NULL;
}

Registration::Registration() {
	RegistrationUI* pcr = new RegistrationUI(this);
}

// Function : bool addNewMember(char name[MAX_STRING], char ssn[MAX_STRING], char id[MAX_STRING], char password[MAX_STRING])
// Description: char name[MAX_STRING] - 회원가입 요청자 이름 char ssn[MAX_STRING] - 회원가입 요청자 주민등록번호, char id[MAX_STRING]- 회원가입 요청자 아이디, char password[MAX_STRING] - 회원가입 요청자 비밀번호
// Parameter: Member* new_user - 회원가입을
// Created: 2022/5/31 22:00
// Author: 서동우

bool Registration::addNewMember(char name[MAX_STRING], char ssn[MAX_STRING], char id[MAX_STRING], char password[MAX_STRING]) {
	// 회원가입 여부는 MemberCollection 클래스가 판단한다.
	if (member_list->verifyNewMember(id)) {
		Member *f = new Member(name, ssn, id, password);
		return true;
	}
	return false;
}

// Function : RegistrationUI(Registration* pc)
// Description: 회원가입 UI 생성후(startInterface 역할). 생성과 함께 파일읽기 요청후 control class에 회원가입을 요청한 후에 성공 결과에 따라 결과를 파일에 출력
// parameter: Registration* pc - 생성을 요청한 control 클래스
// Created: 2022/6/2/13:20
// Author: 서동우

RegistrationUI::RegistrationUI(Registration* pc) {
	// input.txt에서 회원가입정보 읽기(name, ssn, id, password)
	submitBasicInformation();
	if (pc->addNewMember(name, ssn, id, password)) {
		showInformation();
	}

}

// Function : submitBasicInformation()
// Description: Registration의 boundary class에서 입력값으로 input.txt에서 입력을 읽음
// Created: 2022/6/2/13:20
// Author: 서동우

void RegistrationUI::submitBasicInformation() {
	fscanf(in_fp, "%s %s %s %s", name, ssn, id, password);
}

// Function : showInformation()
// Description: Registration의 boundary class에서 output.txt에 결과 출력
// Created: 2022/6/2/13:20
// Author: 서동우

void RegistrationUI::showInformation() {
	fprintf(out_fp, "%s %s %s %s\n\n", name, ssn, id, password);
}

// Function : LogOn()
// Description: LogOn의 control class 생성시 LogOn의 boundary class(UI) 생성
// Created: 2022/6/2/13:20
// Author: 서동우

LogOn::LogOn() {
	LogOnUI* pcr = new LogOnUI(this);
}

// Function : bool requestLogOn(char id[MAX_STRING], char password[MAX_STRING])
// Description: 로그인 가능한지 veriyMember를 호출하여, 요청 결과를 반환
// Parameter: char id[MAX_STRING] - 로그인을 요청한 아이디, char password[MAX_STRING] - 로그인을 요청한 비밀번호
// Return Value: 로그인 요청이 성공하면 true를 반환
// Created: 2022/5/31 22:00
// Author: 서동우

bool LogOn::requestLogOn(char id[MAX_STRING], char password[MAX_STRING]) {
	if (member_list->verifyMember(id, password)) {

		return true;
	}
	return false;
}

// Function : LogOnUI(LogOn* pc)
// Description: 로그인 UI 생성후(startInterface 역할). 생성과 함께 파일읽기 요청후 cotrol class에 로그인을 요청한 후에 성공 결과에 따라 결과를 파일에 출력
// Parameter: LogOn* pc - boundary 클래스 생성을 요청한 control class
// Created: 2022/5/31 22:00
// Author: 서동우

LogOnUI::LogOnUI(LogOn* pc) {
	userLogOn();
	if (pc->requestLogOn(id, password)) {
		showInformation();
	}

}

// Function : submitBasicInformation()
// Description: LogOn의 boundary class에서 입력값을 input.txt에서 읽음
// Created: 2022/6/2/13:20
// Author: 서동우

void LogOnUI::userLogOn() {
	fscanf(in_fp, "%s %s", id, password);
}

// Function : showInformation()
// Description: LogOn의 boundary class에서 output.txt에 결과 출력
// Created: 2022/6/2/13:20
// Author: 서동우

void LogOnUI::showInformation() {
	fprintf(out_fp, "%s %s\n\n", id, password);
}

// Function : LogOut()
// Description: LogOut의 control class 생성시 LogOut의 boundary class(UI) 생성
// Created: 2022/6/2/13:20
// Author: 서동우

LogOut::LogOut() {
	LogOutUI* pcr = new LogOutUI(this);
}

// Function : LogOut()
// Description: 회원의 로그아웃 요청을 처리 
// Created: 2022/6/2/13:20
// Author: 서동우

void LogOut::requestLogOut() {
	member_list->deactivateMember();
}

// Function : LogOutUI(LogOut* pc)
// Description: 로그아웃 UI 생성후(startInterface 역할). 생성과 함께 파일읽기 후에 control class에 로그아웃을 요청한 후에 결과를 파일에 출력
// Parameter: LogOut* pc - boundary 클래스 생성을 요청한 control class
// Created: 2022/5/31 22:00
// Author: 서동우

LogOutUI::LogOutUI(LogOut* pc) {
	userLogOut();
	pc->requestLogOut();
	showInformation();
}

// Function : userLogOut()
// Description: 로그인한 회원의 로그아웃 결과 출력을 위해 로그아웃전에 로그인 회원의 이름을 저장.
// Created: 2022/6/2/13:20
// Author: 서동우

void LogOutUI::userLogOut() {
	strcpy(id, member_list->activeMember->getId());
}

// Function : showInformation()
// Description: LogOut의 boundary class에서 output.txt에 결과 출력
// Created: 2022/6/2/13:20
// Author: 서동우

void LogOutUI::showInformation() {
	fprintf(out_fp, "%s\n\n", id);
}

// Function : Withdraw()
// Description: Withdraw()의 control class 생성시 Withdarw의 boundary class(UI) 생성
// Created: 2022/6/2/13:20
// Author: 서동우

Withdraw::Withdraw() {
	WithdrawUI* pcr = new WithdrawUI(this);
}

// Function : Withdraw()
// Description: 컬렉션에서 회원탈퇴를 요청한 Member를 삭제
// Created: 2022/6/2/13:20
// Author: 서동우

void Withdraw::withdrawMember() {
	member_list->removeMemberFromCollection();
}

// Function : WithdrawUI(Withdraw* pc)
// Description: 회원탈퇴 UI 생성후(startInterface 역할) 생성과 함께 회원탈퇴를 요청한 회원의 이름 저장후 control class에 회원탈퇴 요청후에 결과를 파일에 출력
// Parameter: LogOut* pc - boundary 클래스 생성을 요청한 control class
// Created: 2022/5/31 22:00
// Author: 서동우

WithdrawUI::WithdrawUI(Withdraw* pc) {
	requestWithdraw();
	pc->withdrawMember();
	showInformation();
}

// Function : userLogOut()
// Description: 로그인한 회원의 회원탈퇴 결과 출력을 위해 회원탈퇴저에 로그인 회원의 이름을 저장.
// Created: 2022/6/2/13:20
// Author: 서동우

void WithdrawUI::requestWithdraw() {
	strcpy(id, member_list->activeMember->getId());
}

// Function : showInformation()
// Description: Withdraw의 boundary class에서 output.txt에 결과 출력
// Created: 2022/6/2/13:20
// Author: 서동우

void WithdrawUI::showInformation() {
	fprintf(out_fp, "%s\n\n", id);
}