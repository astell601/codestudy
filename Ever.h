#ifndef __EVER_H_
#define __EVER_H_
#include <iostream>
#include "land.h"
using namespace std;

class Payment
{
private : 
	int Teen_price = 47000, Adult_price = 56000, Senior_price = 44000;
	int Teen, Adult, Senior;
	int TOTAL, Check, Money, Pay_Money;
	bool ticket = false;

public : 
	Payment();
	int Buyticket(int n, int k, int i);
	void Showdata();
};

#endif
