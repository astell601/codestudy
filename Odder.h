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
        int SUM;
        cout << "1. �ܹ��� 2. ����Ƣ�� 3.�ݶ� 4. ��Ʈ 5. ���̽�ũ��" << endl;
        cout << "������ ������ �Է����ּ���." << endl;

        while ('\n' == 1)
        {
            cin >> NUM1 >> NUM2;
            menu.InitMembers(NUM1);
            SUM = menu.SaleMenu(NUM2);
            SUM += SUM;
        }
        cout << endl << "������" << SUM << "���Դϴ�." << endl;

        cout << "1. ī�� ���� 2. ���� ����" << endl;
        cin >> PAY; 
        if (PAY == 1)
            cout << "���� �Ϸ�" << endl;
        else if (PAY == 2)
        {
            cout << "�󸶸� ���ðڽ��ϱ�?" << endl;
            cin >> MONEY;
            cout << "�Ž�������" << MONEY - menu.SaleMenu(NUM2)<< "���Դϴ�." << endl;
        }

        else
            cout << "�߸��� �Է��Դϴ�." << endl;

    }
};
#endif;