#pragma once

/*
* 2022.03.26 은행계좌 관리 프로그램
* 기능1. 계좌개설
* 기능2. 입금
* 기능3. 출금
* 기능4. 전체고객 잔액조회
* 
* 고객의 계좌정보 : 계좌번호, 고객이름, 잔액
*/
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main();

class Customer
{
private:
	int accID; //계좌번호
	int balance; //잔액
	char cusName[NAME_LEN]; //이름

public:
	Customer();
	~Customer();
	void MakeAccount(); //계좌개설
	void DepositMoney(int money); //입금
	int WithdrawMoney(int money); //출금
	int ShowBalance(); //잔액조회
	void ShowCustomerInfomation(); //고객정보 보기
};
