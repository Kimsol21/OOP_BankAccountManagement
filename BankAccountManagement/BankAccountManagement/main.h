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

int main();
void MainProcess();

class Customer
{
private:
	int account; //���¹�ȣ
	int balance; //�ܾ�
	char* name; //�̸�

public:
	Customer();
	~Customer();
	void MakeAccount(int account, int balance, char* name); //���°���
	void Deposit(int money); //�Ա�
	int Withdraw(int money); //���
	int ShowBalance(); //�ܾ���ȸ
	void ShowCustomerInfomation(); //������ ����
};
