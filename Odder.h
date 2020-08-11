#ifndef __ODDER_H_
#define __ODDER_H_
#include <iostream>
#include "Menu.h"
using namespace std;

class Odder
{
private:
    MENU menu;
    int NUM1, NUM2, MONEY, PAY;
public:
    void InitMembers(int num1, int num2, int money, int pay)
    {
        NUM1 = num1;
        NUM2 = num2;
        MONEY = money;
        PAY = pay;
    }

    void Oddering(void)
    {
        int SUM = 0;
        cout << "맥도날드 숭실대점에 오신 것을 환영합니다!" << endl;
        cout << "1. 햄버거 2. 감자튀김 3.콜라 4. 세트 5. 아이스크림" << endl;
        cout << "종류와 갯수를 입력해주세요." << endl;

        cin >> NUM1 >> NUM2;
        menu.InitMembers(NUM1);
        SUM = menu.SaleMenu(NUM2);
    
        cout << endl << "가격은" << SUM << "원입니다." << endl;

        cout << "1. 카드 결제 2. 현금 결제" << endl;
        cin >> PAY;
        if (PAY == 1)
            cout << "결제 완료" << endl;
        else if (PAY == 2)
        {
            cout << "얼마를 내시겠습니까?" << endl;
            cin >> MONEY;
            cout << "거스름돈은" << MONEY - menu.SaleMenu(NUM2) << "원입니다." << endl;
        }

        else
            cout << "잘못된 입력입니다." << endl;

    }
};
#endif;
