#include <iostream>
#include "main.h"

using namespace std;

int main()
{
	MainProcess();

	return 0;
}

void MainProcess()
{	
	bool exit = false;
	int input = 0;
	int tempAccountNum = 0;
	int tempMoney = 0;

	Customer* CustomerList = new Customer[20]();
	int maxCustomerCount = 0;

	while (false == exit)
	{
		cout << endl<<"----------<Menu>----------" << endl;
		cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl;
		cout << "------------------------------" << endl<<endl;
		cin >> input;

		char* tempName = new char[10];
		switch (input)
		{
		case 1: //���°���
			cout << "�� �̸��� �Է��ϼ���." << endl;
			cin >> tempName;
			CustomerList[maxCustomerCount].MakeAccount(maxCustomerCount, 0, tempName); 
			maxCustomerCount++;
			cout << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
			cout << "���̸� : " << tempName << endl << "���¹�ȣ : "<<maxCustomerCount-1 <<endl;
			break;

		case 2: //�Ա�
			cout << "�Ա��Ͻ� ���¹�ȣ�� �Է��ϼ���." << endl;
			cin >> tempAccountNum;
			cout << "�Ա��Ͻ� �ݾ��� �Է��ϼ���." << endl;
			cin >> tempMoney;

			CustomerList[tempAccountNum].Deposit(tempMoney);

			cout << "����ó���Ǿ����ϴ�." << endl;
			CustomerList[tempAccountNum].ShowCustomerInfomation();
			break;

		case 3: //���
			cout << "����Ͻ� ���¹�ȣ�� �Է��ϼ���." << endl;
			cin >> tempAccountNum;
			cout << "����Ͻ� �ݾ��� �Է��ϼ���." << endl;
			cin >> tempMoney;
			if (-1 == CustomerList[tempAccountNum].Withdraw(tempMoney))
			{
				cout << "�ܾ��� �����մϴ�." << endl;
				break;
			}
			CustomerList[tempAccountNum].Withdraw(tempMoney);
			cout << "����ó���Ǿ����ϴ�." << endl;
			CustomerList[tempAccountNum].ShowCustomerInfomation();
			break;

		case 4: //�������� ��ü ���
			for (int i = 0; i < maxCustomerCount; i++)
			{
				CustomerList[i].ShowCustomerInfomation();
			}
			break;

		case 5: //���α׷� ����
			exit = true;
			break;

		default:
			cout << "�ùٸ� �޴��� �����ϼ���." << endl;
			break;
		}
	}
}

Customer::Customer() :account(0), balance(0), name(0)
{
}

Customer::~Customer()
{
}

void Customer::MakeAccount(int account, int balance, char* name)
{
	this->account = account;
	this->balance = balance;

	char* tempName = new char();
	this->name = name;
}

void Customer::Deposit(int money)
{
	this->balance += money;
}

int Customer::Withdraw(int money)
{
	if (balance < money) return -1;
	this->balance -= money;
	return 0;
}

int Customer::ShowBalance()
{
	return this->balance;
}

void Customer::ShowCustomerInfomation()
{
	cout << "���̸� : " << name << endl << "���¹�ȣ : " << account << endl << "�ܾ� : " << balance <<endl;
}
