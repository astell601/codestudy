#include <iostream>
#include "Ever.h"
using namespace std;

Payment::Payment() :TOTAL(0) {
	Payment pay;
	cout << "꿈과 환상의 나라 에버랜드에 오신 것을 환영합니다." << endl;
	cout << "청소년, 대인, 경로/소인의 인원 수를 입력해주세요. " << endl;
	pay.Buyticket();


}

int Payment::Buyticket(int n, int k, int i) {
	Teen = n;
	Adult = k;
	Senior = i;

	TOTAL = Teen * Teen_price + Adult * Adult_price + Senior * Senior_price;

	return TOTAL;

}

void Payment::Showdata(){
	cout << "청소년 : " << Teen << "명" << endl;
	cout << "성인 : " << Adult << "명" << endl;
	cout << "소인/경로 : " << Senior << "명" << endl;
	cout << "총 금액은 " << TOTAL << "원 입니다." << endl;

	cout << "맞으면 Y 틀리면 N을 눌러주세요." << endl;
	cin >> Check;

	while (Check != 'Y' && Check != 'N') {
		cout << "다시 입력해주세요" << endl;
		cout << "맞으면 Y 틀리면 N을 눌러주세요." << endl;
		cin >> Check;
	}

	if (Check == 'Y') {
		cout << "현금 결제와 카드 결제 중 선택해주세요." << endl;
		cin >> Money;
		if (Money == '현금') {
			cout << "얼마를 지불하시겠습니까?" << endl;
			cin >> Pay_Money;
			cout << "거스름돈은 " << Pay_Money - TOTAL << "원입니다." << endl;
			cout << "에버랜드에서 즐거운 시간 되세요" << endl;
			bool ticket = true;
		}
		else if (Money == '카드') {
			cout << "에버랜드에서 즐거운 시간 되세요" << endl;
			bool ticket = true;
		}
		else
			cout << "거래 수단을 올바르게 선택하세요" << endl;
	}
	else {
		cout << "결제를 처음부터 다시 진행합니다." << endl;
		system("cls"); //clear screen
	}
}
