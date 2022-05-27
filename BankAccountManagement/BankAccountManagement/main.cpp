/*
* Banking System Ver 0.1
* �ۼ��� : �� ��
* ���� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
*/

#include <iostream>
#include "main.h"

using namespace std;

Customer accArr[100];
int accNum = 0;

int main()
{
	int choice = 0;
	int tempAccountNum = 0;
	int tempMoney = 0;

	while (1)
	{
		cout << endl << "----------<Menu>----------" << endl;
		cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl;
		cout << "------------------------------" << endl << endl;
		cin >> choice;

		switch (choice)
		{
		case MAKE: //���°���
			accArr[accNum].MakeAccount();
			break;

		case DEPOSIT: //�Ա�
			cout << "�Ա��Ͻ� ���¹�ȣ�� �Է��ϼ���." << endl;
			cin >> tempAccountNum;
			cout << "�Ա��Ͻ� �ݾ��� �Է��ϼ���." << endl;
			cin >> tempMoney;

			accArr[tempAccountNum].DepositMoney(tempMoney);

			cout << "����ó���Ǿ����ϴ�." << endl;
			accArr[tempAccountNum].ShowCustomerInfomation();
			break;

		case WITHDRAW: //���
			cout << "����Ͻ� ���¹�ȣ�� �Է��ϼ���." << endl;
			cin >> tempAccountNum;
			cout << "����Ͻ� �ݾ��� �Է��ϼ���." << endl;
			cin >> tempMoney;
			if (-1 == accArr[tempAccountNum].WithdrawMoney(tempMoney))
			{
				cout << "�ܾ��� �����մϴ�." << endl;
				break;
			}
			cout << "����ó���Ǿ����ϴ�." << endl;
			accArr[tempAccountNum].ShowCustomerInfomation();
			break;

		case INQUIRE: //�������� ��ü ���
			for (int i = 0; i < accNum; i++)
			{
				accArr[i].ShowCustomerInfomation();
			}
			break;

		case EXIT: //���α׷� ����
			return 0;

		default:
			cout << "�ùٸ� �޴��� �����ϼ���." << endl;
		}
	}
	return 0;
}

Customer::Customer() :accID(0), balance(0)
{
}

Customer::~Customer()
{
}

void Customer::MakeAccount()
{	
	
	cout << "�� �̸��� �Է��ϼ���." << endl;
	cin >> this->cusName;
	this->balance = 0;
	this->accID = accNum;
	cout << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
	accNum++;
	cout << "���̸� : " << this->cusName << endl << "���¹�ȣ : " << this->accID << endl;
}

void Customer::DepositMoney(int money)
{
	this->balance += money;
}

int Customer::WithdrawMoney(int money)
{
	if (balance >= money)
	{
		this->balance -= money;
	}
	else return -1;
	return 0;
}

int Customer::ShowBalance()
{
	return this->balance;
}

void Customer::ShowCustomerInfomation()
{
	cout << "���̸� : " << this->cusName << endl << "���¹�ȣ : " << this->accID << endl << "�ܾ� : " << this->balance <<endl;
}
