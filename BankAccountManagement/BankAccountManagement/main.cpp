/*
* Banking System Ver 0.1
* 작성자 : 김 솔
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
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
		cout << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl;
		cout << "------------------------------" << endl << endl;
		cin >> choice;

		switch (choice)
		{
		case MAKE: //계좌개설
			accArr[accNum].MakeAccount();
			break;

		case DEPOSIT: //입금
			cout << "입금하실 계좌번호를 입력하세요." << endl;
			cin >> tempAccountNum;
			cout << "입금하실 금액을 입력하세요." << endl;
			cin >> tempMoney;

			accArr[tempAccountNum].DepositMoney(tempMoney);

			cout << "정상처리되었습니다." << endl;
			accArr[tempAccountNum].ShowCustomerInfomation();
			break;

		case WITHDRAW: //출금
			cout << "출금하실 계좌번호를 입력하세요." << endl;
			cin >> tempAccountNum;
			cout << "출금하실 금액을 입력하세요." << endl;
			cin >> tempMoney;
			if (-1 == accArr[tempAccountNum].WithdrawMoney(tempMoney))
			{
				cout << "잔액이 부족합니다." << endl;
				break;
			}
			cout << "정상처리되었습니다." << endl;
			accArr[tempAccountNum].ShowCustomerInfomation();
			break;

		case INQUIRE: //계좌정보 전체 출력
			for (int i = 0; i < accNum; i++)
			{
				accArr[i].ShowCustomerInfomation();
			}
			break;

		case EXIT: //프로그램 종료
			return 0;

		default:
			cout << "올바른 메뉴를 선택하세요." << endl;
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
	
	cout << "고객 이름을 입력하세요." << endl;
	cin >> this->cusName;
	this->balance = 0;
	this->accID = accNum;
	cout << "계좌 개설이 완료되었습니다." << endl;
	accNum++;
	cout << "고객이름 : " << this->cusName << endl << "계좌번호 : " << this->accID << endl;
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
	cout << "고객이름 : " << this->cusName << endl << "계좌번호 : " << this->accID << endl << "잔액 : " << this->balance <<endl;
}
