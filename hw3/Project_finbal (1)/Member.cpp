#include "Member.h"

// Main �Լ����� ����ϴ� ������ �����ؼ� ����ϱ� ����

extern FILE* in_fp, *out_fp;
extern MemberCollection* member_list;

// Member ��ü�� �����ɽÿ� �ڵ����� ���� ����Ʈ�� �߰��մϴ�.
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

//member collection ���Ĥ�

bool MemberCollection::verifyNewMember(char id_[MAX_STRING]) {
	// MemberCollection�� ����Ʈ�� 0�� ���� ���Ե� Member�� �����Ƿ� �ٷ� return true�� ���ݴϴ�.
	if (ownedMember.size() > 0) {
		// MemberCollection�� ������ �ִ� Member���� ������� Ȯ���ذ��鼭 ��û�� id�� ������ id�� �߰ߵ��� ���� ��츸 return true�� ��ȯ�մϴ�.
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

//�α���
bool MemberCollection::verifyMember(char id_[MAX_STRING], char password_[MAX_STRING]) {
	// MemberCollection�� ����Ʈ�� 0�� ���� ���Ե� Member�� �����Ƿ� �ٷ� return true�� ���ݴϴ�.
	if (ownedMember.size() > 0) {
		// MemberCollection�� ������ �ִ� Member���� ������� Ȯ���ذ��鼭 ��û�� id�� ������ id�� �߰ߵ��� ���� ��츸 return true�� ��ȯ�մϴ�.
		for (auto member : ownedMember) {
			if (strcmp((member)->getId(), id_) == 0 && strcmp((member)->getPassword(), password_) == 0) {
				makeMemberActive(member);
				return true;
			}
		}
	}
	return false;
}
// �α����� ������ ����Ű���� �Ѵ�.
void MemberCollection::makeMemberActive(Member* pcr) {
	activeMember = pcr;
}
// ���Ǹ� ���� ��� �÷��ǿ��� ��ü�� �����ϵ��� ����
void MemberCollection::removeMember() {
	delete activeMember;
	activeMember = NULL;
}
void MemberCollection::deactivateMember() {
	activeMember = NULL;
}

//ȸ������

// ȸ������ control Ŭ���� ȣ��� �ڵ����� UI Ŭ������ ȣ��ǵ��� �Ͽ����ϴ�.
Registration::Registration() {
	RegistrationUI* pcr = new RegistrationUI(this);
}
// ȸ�������� ���ε� ��츸 return true�� ��ȯ�Ѵ�.

bool Registration::addNewMember(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]) {
	// ȸ������ ���δ� MemberCollection Ŭ������ �Ǵ��Ѵ�.
	if (member_list->verifyNewMember(id_)) {
		Member *f = new Member(name_, ssn_, id_, password_);
		return true;
	}
	return false;
}

// ȸ������ UI Ŭ������ �����ڴ� ������ ��û�� control Ŭ������ �״�� �޾ƿɴϴ�.
RegistrationUI::RegistrationUI(Registration* pc) {
	// input.txt���� ȸ���������� �б�(name, ssn, id, password)
	SubmitBasicInformation();
	// input.txt���� ȸ�����Կ� �ʿ��� ������ ���� �Ŀ�, control Ŭ������ ȸ�������� ��û�Ѵ�.
	if (pc->addNewMember(name, ssn, id, password)) {
		// addNewMember���� ȸ�����Կ� ������ ��쿡�� output.txt�� ��°��� �߰��Ѵ�. ������ ���� ��°��� ���� �ʴ´�.
		ShowInformation();
	}

}

// input.txt���� �Է¹ޱ�
void RegistrationUI::SubmitBasicInformation() {
	fscanf(in_fp, "%s %s %s %s", name, ssn, id, password);
}

// output.txt�� �������
void RegistrationUI::ShowInformation() {
	fprintf(out_fp, "%s %s %s %s\n\n", name, ssn, id, password);
}


//�α��� �Լ�

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
	// input.txt���� ȸ���������� �б�(name, ssn, id, password)
	userLogOn();
	// input.txt���� ȸ�����Կ� �ʿ��� ������ ���� �Ŀ�, control Ŭ������ ȸ�������� ��û�Ѵ�.
	if (pc->requestLogOn(id, password)) {
		// addNewMember���� ȸ�����Կ� ������ ��쿡�� output.txt�� ��°��� �߰��Ѵ�. ������ ���� ��°��� ���� �ʴ´�.
		ShowInformation();
	}

}
// input.txt���� �Է¹ޱ�
void LogOnUI::userLogOn() {
	fscanf(in_fp, "%s %s", id, password);
}
// output.txt�� �������
void LogOnUI::ShowInformation() {
	fprintf(out_fp, "%s %s\n\n", id, password);
}


// logout ����

LogOut::LogOut() {
	LogOutUI* pcr = new LogOutUI(this);
}

void LogOut::requestLogout() {
	member_list->deactivateMember();
}

LogOutUI::LogOutUI(LogOut* pc) {
	// input.txt���� ȸ���������� �б�(name, ssn, id, password)
	clickLogout();
	pc->requestLogout();
	ShowInformation();
	// input.txt���� ȸ�����Կ� �ʿ��� ������ ���� �Ŀ�, control Ŭ������ ȸ�������� ��û�Ѵ�.
}
// clickLogout() ����� �α��ε� ȸ���� id�� �����´ٰ� ����(delete �ϱ� ���� ������)
void LogOutUI::clickLogout() {
	strcpy(id, member_list->activeMember->getId());
}
// output.txt�� �������
void LogOutUI::ShowInformation() {
	fprintf(out_fp, "%s\n\n", id);
}

// ȸ��Ż��
Withdraw::Withdraw() {
	WithdrawUI* pcr = new WithdrawUI(this);
}

void Withdraw::withdrawMember() {
	member_list->removeMember();
}


WithdrawUI::WithdrawUI(Withdraw* pc) {
	// input.txt���� ȸ���������� �б�(name, ssn, id, password)
	requestWithdraw();
	pc->withdrawMember();
	ShowInformation();
	// input.txt���� ȸ�����Կ� �ʿ��� ������ ���� �Ŀ�, control Ŭ������ ȸ�������� ��û�Ѵ�.
}

// requestWithdraw() ����� �α��ε� ȸ���� id�� �����´ٰ� ����(delete �ϱ� ���� ������)
void WithdrawUI::requestWithdraw() {
	strcpy(id, member_list->activeMember->getId());
}
// output.txt�� �������
void WithdrawUI::ShowInformation() {
	fprintf(out_fp, "%s\n\n", id);
}