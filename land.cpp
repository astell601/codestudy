#include <iostream>
#include "land.h"
#include <ctime> //time()을 가지고 있는 헤더파일
#include <Windows.h> //Sleep()을 가지고 있는 헤더파일
using namespace std;

void Rollercoaster::Riding{
	int elapsedSeconds = 0;
	
	while (ticket) {
		Sleep(duration);

		elapsedSeconds++;
		cout << "경과 시간 : " < elapsedSeconds << endl;
	}

	Sleep(5000);//5초간 정지

}

