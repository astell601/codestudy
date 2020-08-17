#ifndef __LAND_H_
#define __LAND_H_
#include <iostream>
#include "Ever.h"
#include <ctime> //time()을 가지고 있는 헤더파일
#include <Windows.h> //Sleep()을 가지고 있는 헤더파일
using namespace std;

class Rollercoaster {
private :
	int TOTAL_PEOPLE = 16;
	const int duration = 5000;

public : 
	int Ready();
	void Riding();

};

class Biking {
	Rollercoaster rol;
	rol.Ready();
	rol.Riding();

};

class Flumride {
	Rollercoaster rol2;
	rol2.Reday();
	rol2.Riding();

};

#endif
