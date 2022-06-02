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
	//�������: �̸�, �ֹι�ȣ, ���̵�, ��� (��� ���ÿ� ���� �̸��� ������ϴ�.)
	char name[MAX_STRING], ssn[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
	PurchasedProductCollection myPurchaseList;
public:
	//������
	Member(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]);
	//������(ȸ��������) ����� id ��ȯ
	char* getId();
	//�α��� �߰�
	char* getPassword();
	ProductCollection now_product_collection;

	//�߰��κ�:
	PurchasedProductCollection getPurchasedProductCollection();
};

// Member entity ���� Ŭ���� (MemberCollection:Member, 1:Many����)
class MemberCollection {
public:
	Member* activeMember{ 0 }; //����α��ε� ���� ǥ��

	//vector�� �̿��Ͽ� ������ Member ��ä���� �����մϴ�. (ó���� private�� �ߴµ� �ٸ��е� ������ ����Ͽ� public���� �����Ͽ����ϴ�.)
	vector<Member*> ownedMember;
	vector<Member*>::iterator member_iterator; //�ݺ��� ����
	//���ο� ȸ������ ��û�� ���� ��� ������ ���̵� �������� �ʴ� ��츸 ȸ�������� �� �� �ְ� return true�� ��ȯ�մϴ�.
	bool verifyNewMember(char id_[MAX_STRING]);
	void addMembertoCollection(Member* new_user);

	//�α���
	bool verifyMember(char id_[MAX_STRING], char password_[MAX_STRING]);
	// �α����� ������ ����Ű���� �Ѵ�.
	void makeMemberActive(Member* pcr);
	// ���Ǹ� ���� ��� �÷��ǿ��� ��ü�� �����ϵ��� ����
	void removeMember();
	void deactivateMember();

};

// DB �� �ܺ����� ��ġ�� ������ �Ǿ����� �����Ƿ� �����Լ��� ����� MemberCollection Ŭ������ new�� ������ Member ��ü�� �����Ѵ�. (�ߺ� ���� Ȯ�� �� �α��� Ȯ��)
class Registraion;
class RegistrationUI;

class Registration {
public:
	Registration();
	// ȸ������ UI Ŭ�������� ȸ������ ��û�� ���� ��� ����
	// ȸ�������� ���ε� ��츸 return true�� ��ȯ�Ѵ�.
	bool addNewMember(char name_[MAX_STRING], char ssn_[MAX_STRING], char id_[MAX_STRING], char password_[MAX_STRING]);
};

class RegistrationUI {
private:
	//�������
	char user_type[MAX_STRING], name[MAX_STRING], ssn[MAX_STRING], address[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
public:
	RegistrationUI(Registration* pc);
	// input.txt���� �Է¹ޱ�
	void SubmitBasicInformation();
	// output.txt�� �������
	void ShowInformation();
};


class LogOn {
public:
	LogOn();
	bool requestLogOn(char id_[MAX_STRING], char password_[MAX_STRING]);
};

class LogOnUI {
private:
	//�������
	char id[MAX_STRING], password[MAX_STRING];


public:
	LogOnUI(LogOn* pc);
	// input.txt���� �Է¹ޱ�
	void userLogOn();
	// output.txt�� �������
	void ShowInformation();

};

// �α׾ƿ� use case
class LogOut;
class LogOutUI;

class LogOut {
public:
	LogOut();
	// ȸ��Ż��� �α��ε� ���¿��� �Ѵٰ� �����ϹǷ� ������ �����Ѵ�. ���� void�� ����.
	void requestLogout();
};

class LogOutUI {
private:
	//�������
	char id[MAX_STRING];
public:
	LogOutUI(LogOut* pc);
	// clickLogout() ����� �α��ε� ȸ���� id�� �����´ٰ� ����(delete �ϱ� ���� ������)
	void clickLogout();
	// output.txt�� �������
	void ShowInformation();
};


// ȸ��Ż�� use case
class Withdraw;
class WithdrawUI;

class Withdraw {
public:
	Withdraw();
	// ȸ��Ż��� �α��ε� ���¿��� �Ѵٰ� �����ϹǷ� ������ �����Ѵ�. ���� void�� ����.
	void  withdrawMember();
};

class WithdrawUI {
private:
	//�������
	char id[MAX_STRING];


public:
	WithdrawUI(Withdraw* pc);
	// requestWithdraw() ����� �α��ε� ȸ���� id�� �����´ٰ� ����(delete �ϱ� ���� ������)
	void requestWithdraw();
	// output.txt�� �������
	void ShowInformation();

};
