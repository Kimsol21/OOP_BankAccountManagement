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
		cout << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl;
		cout << "------------------------------" << endl<<endl;
		cin >> input;

		char* tempName = new char[10];
		switch (input)
		{
		case 1: //계좌개설
			cout << "고객 이름을 입력하세요." << endl;
			cin >> tempName;
			CustomerList[maxCustomerCount].MakeAccount(maxCustomerCount, 0, tempName); 
			maxCustomerCount++;
			cout << "계좌 개설이 완료되었습니다." << endl;
			cout << "고객이름 : " << tempName << endl << "계좌번호 : "<<maxCustomerCount-1 <<endl;
			break;

		case 2: //입금
			cout << "입금하실 계좌번호를 입력하세요." << endl;
			cin >> tempAccountNum;
			cout << "입금하실 금액을 입력하세요." << endl;
			cin >> tempMoney;

			CustomerList[tempAccountNum].Deposit(tempMoney);

			cout << "정상처리되었습니다." << endl;
			CustomerList[tempAccountNum].ShowCustomerInfomation();
			break;

		case 3: //출금
			cout << "출금하실 계좌번호를 입력하세요." << endl;
			cin >> tempAccountNum;
			cout << "출금하실 금액을 입력하세요." << endl;
			cin >> tempMoney;
			if (-1 == CustomerList[tempAccountNum].Withdraw(tempMoney))
			{
				cout << "잔액이 부족합니다." << endl;
				break;
			}
			CustomerList[tempAccountNum].Withdraw(tempMoney);
			cout << "정상처리되었습니다." << endl;
			CustomerList[tempAccountNum].ShowCustomerInfomation();
			break;

		case 4: //계좌정보 전체 출력
			for (int i = 0; i < maxCustomerCount; i++)
			{
				CustomerList[i].ShowCustomerInfomation();
			}
			break;

		case 5: //프로그램 종료
			exit = true;
			break;

		default:
			cout << "올바른 메뉴를 선택하세요." << endl;
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
	cout << "고객이름 : " << name << endl << "계좌번호 : " << account << endl << "잔액 : " << balance <<endl;
}
