#ifndef __SCHOOL_H_
#define __SCHOOL_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class House {
private:
	int alarm;
	char finish_alarm;
	int weather;
	int spend_time;

public:
	House() :alarm(5), weather(5), spend_time(0), finish_alarm(0) {}

	int Get_Up() {
		for (int i = 0; i < alarm; i++) {
			cout << "BZZZ... ��ħ�Դϴ�. �Ͼ����..." << endl;
			cout << "�˶� ����� Y, ������� N�� �����ּ���..." << endl;
			cin >> finish_alarm;
			if (finish_alarm == 'Y') break;
			else if (finish_alarm == 'N') continue;
			else continue;
			spend_time += 5;
		}
		return spend_time;
	}

	int TodayWeather() {

		srand((unsigned int)time(NULL));

		while (1) {
			int num = rand();
			weather = (int)num % 10;
			if (weather < 3) break;
		}

		return weather;
	}

	int Get_time() {
		return spend_time;
	}

};

class Transportation {
public:
	virtual void  Get_Ride(House &h) = 0;
};

class Bus : public Transportation {
private:
	int spend_time;
	int take_time;
	string Todayweather[40] = { "�ذ� ¸¸�Ͽ�", "�����", "�� �ͼ�" };
	int spendweather[4] = { 30, 45, 60 };

public:
	Bus() :spend_time(0), take_time(0) {}

	virtual void Get_Ride(House& h) {
		take_time = h.TodayWeather();
		cout << "\n";
		cout << "���� ������ " << Todayweather[take_time] << " ���� ���� ���� �����Դϴ�." << endl << endl;
		spend_time += spendweather[take_time];
	}

	int Get_time() {
		return spend_time;
	}

};

class Subway : public Transportation {
private:
	int spend_time;
	int take_time;

public:
	Subway() : spend_time(0), take_time(0) {}

	virtual void Get_Ride(House& h) {
		take_time = h.TodayWeather();
		if (take_time == 0)
			spend_time += 25;
		else
			spend_time += 35;
	}
	int Get_time() {
		return spend_time;
	}
};

class ITstudyroom {
private:
	char coffee;
	int spend_time;

public:
	ITstudyroom():coffee(0), spend_time(0){}
	int Buycoffee() {
		cout << "Ŀ�Ǹ� �� ������ ���ðڽ��ϱ�?(Y/N)" << endl;
		cin >> coffee;
		
		if (coffee == 'Y') {
			spend_time += 15;
		}
		else {
			spend_time += 5;
		}

		return spend_time;
	}
	int Get_time() {
		return spend_time;
	}
};

class Howlong {
private:
	int spend_time;
	int hours;
	int minutes;

public:
	int ArriveSchool(House& h, Bus& b, Subway& s, ITstudyroom& i) {
		spend_time = h.Get_time() + b.Get_time() + s.Get_time() + i.Get_time();
		
		return spend_time;
	}

	int Totaltime() {
		hours = spend_time / 60;
		minutes = spend_time % 60;

		return hours, minutes;
	}

	void CheckupLate() {
		hours += 8;
		minutes += 30;
		if (minutes > 59) {
			hours += 1;
			minutes -= 60;
		}
		if (hours > 9) {
			cout << "\n";
			cout << "������ " << hours << "�� " << minutes << "�� �Դϴ�." << endl;
			cout << "������ �����Դϴ�. �Ф�" << endl;
		}
		else {
			cout << "\n";
			cout << "������ " << hours << "�� " << minutes << "�� �Դϴ�." << endl;
			cout << "�����մϴ�. ���������� �����ϼ̽��ϴ�. ����" << endl;
		}

	}
};



#endif