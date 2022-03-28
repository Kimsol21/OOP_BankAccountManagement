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

int main();
void MainProcess();

class Customer
{
private:
	int account; //계좌번호
	int balance; //잔액
	char* name; //이름

public:
	Customer();
	~Customer();
	void MakeAccount(int account, int balance, char* name); //계좌개설
	void Deposit(int money); //입금
	int Withdraw(int money); //출금
	int ShowBalance(); //잔액조회
	void ShowCustomerInfomation(); //고객정보 보기
};
