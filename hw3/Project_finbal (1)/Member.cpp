#include "Member.h"

// Main 함수에서 사용하는 변수들 공유해서 사용하기 위함

extern FILE* in_fp, *out_fp;
extern MemberCollection* member_list;

// Member 객체가 생성될시에 자동으로 벡터 리스트에 추가합니다.
Member::Member(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]) {
	strcpy(name, name_);
	strcpy(ssn, ssn_);
	strcpy(id, id_);
	strcpy(password, password_);
	member_list->addMembertoCollection(this);
}

char*Member::getId() {
	return id;
}

char*Member::getPassword() {
	return password;
}



PurchasedProductCollection Member::getPurchasedProductCollection() {
	return this->myPurchaseList;
}

//member collection 관렬ㄴ

bool MemberCollection::verifyNewMember(char id_[MAX_STRING]) {
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


void MemberCollection::addMembertoCollection(Member* new_user) {
	ownedMember.push_back(new_user);
}

//로그인
bool MemberCollection::verifyMember(char id_[MAX_STRING], char password_[MAX_STRING]) {
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
void MemberCollection::makeMemberActive(Member* pcr) {
	activeMember = pcr;
}
// 편의를 위해 멤버 컬렉션에서 객체를 삭제하도록 변경
void MemberCollection::removeMember() {
	delete activeMember;
	activeMember = NULL;
}
void MemberCollection::deactivateMember() {
	activeMember = NULL;
}

//회원가입

// 회원가입 control 클래스 호출시 자동으로 UI 클래스가 호출되도록 하였습니다.
Registration::Registration() {
	RegistrationUI* pcr = new RegistrationUI(this);
}
// 회원가입이 승인된 경우만 return true로 반환한다.

bool Registration::addNewMember(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]) {
	// 회원가입 여부는 MemberCollection 클래스가 판단한다.
	if (member_list->verifyNewMember(id_)) {
		Member *f = new Member(name_, ssn_, id_, password_);
		return true;
	}
	return false;
}

// 회원가입 UI 클래스의 생성자는 생성을 요청한 control 클래스를 그대로 받아옵니다.
RegistrationUI::RegistrationUI(Registration* pc) {
	// input.txt에서 회원가입정보 읽기(name, ssn, id, password)
	SubmitBasicInformation();
	// input.txt에서 회원가입에 필요한 정보를 읽은 후에, control 클래스에 회원가입을 요청한다.
	if (pc->addNewMember(name, ssn, id, password)) {
		// addNewMember에서 회원가입에 성공한 경우에만 output.txt에 출력값을 추가한다. 실패한 경우는 출력값을 넣지 않는다.
		ShowInformation();
	}

}

// input.txt에서 입력받기
void RegistrationUI::SubmitBasicInformation() {
	fscanf(in_fp, "%s %s %s %s", name, ssn, id, password);
}

// output.txt에 결과적기
void RegistrationUI::ShowInformation() {
	fprintf(out_fp, "%s %s %s %s\n\n", name, ssn, id, password);
}


//로그인 함수

LogOn::LogOn() {
	LogOnUI* pcr = new LogOnUI(this);
}

bool LogOn::requestLogOn(char id_[MAX_STRING], char password_[MAX_STRING]) {
	if (member_list->verifyMember(id_, password_)) {

		return true;
	}
	return false;
}

LogOnUI::LogOnUI(LogOn* pc) {
	// input.txt에서 회원가입정보 읽기(name, ssn, id, password)
	userLogOn();
	// input.txt에서 회원가입에 필요한 정보를 읽은 후에, control 클래스에 회원가입을 요청한다.
	if (pc->requestLogOn(id, password)) {
		// addNewMember에서 회원가입에 성공한 경우에만 output.txt에 출력값을 추가한다. 실패한 경우는 출력값을 넣지 않는다.
		ShowInformation();
	}

}
// input.txt에서 입력받기
void LogOnUI::userLogOn() {
	fscanf(in_fp, "%s %s", id, password);
}
// output.txt에 결과적기
void LogOnUI::ShowInformation() {
	fprintf(out_fp, "%s %s\n\n", id, password);
}


// logout 관련

LogOut::LogOut() {
	LogOutUI* pcr = new LogOutUI(this);
}

void LogOut::requestLogout() {
	member_list->deactivateMember();
}

LogOutUI::LogOutUI(LogOut* pc) {
	// input.txt에서 회원가입정보 읽기(name, ssn, id, password)
	clickLogout();
	pc->requestLogout();
	ShowInformation();
	// input.txt에서 회원가입에 필요한 정보를 읽은 후에, control 클래스에 회원가입을 요청한다.
}
// clickLogout() 실행시 로그인된 회원의 id를 가져온다고 가정(delete 하기 전에 보관용)
void LogOutUI::clickLogout() {
	strcpy(id, member_list->activeMember->getId());
}
// output.txt에 결과적기
void LogOutUI::ShowInformation() {
	fprintf(out_fp, "%s\n\n", id);
}

// 회원탈퇴
Withdraw::Withdraw() {
	WithdrawUI* pcr = new WithdrawUI(this);
}

void Withdraw::withdrawMember() {
	member_list->removeMember();
}


WithdrawUI::WithdrawUI(Withdraw* pc) {
	// input.txt에서 회원가입정보 읽기(name, ssn, id, password)
	requestWithdraw();
	pc->withdrawMember();
	ShowInformation();
	// input.txt에서 회원가입에 필요한 정보를 읽은 후에, control 클래스에 회원가입을 요청한다.
}

// requestWithdraw() 실행시 로그인된 회원의 id를 가져온다고 가정(delete 하기 전에 보관용)
void WithdrawUI::requestWithdraw() {
	strcpy(id, member_list->activeMember->getId());
}
// output.txt에 결과적기
void WithdrawUI::ShowInformation() {
	fprintf(out_fp, "%s\n\n", id);
}