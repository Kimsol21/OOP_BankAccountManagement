#pragma once

/*
* 2022.03.26 ������� ���� ���α׷�
* ���1. ���°���
* ���2. �Ա�
* ���3. ���
* ���4. ��ü�� �ܾ���ȸ
* 
* ���� �������� : ���¹�ȣ, ���̸�, �ܾ�
*/
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main();

class Customer
{
private:
	int accID; //���¹�ȣ
	int balance; //�ܾ�
	char cusName[NAME_LEN]; //�̸�

public:
	Customer();
	~Customer();
	void MakeAccount(); //���°���
	void DepositMoney(int money); //�Ա�
	int WithdrawMoney(int money); //���
	int ShowBalance(); //�ܾ���ȸ
	void ShowCustomerInfomation(); //������ ����
};
