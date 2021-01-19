#include <iostream>
#include <queue>
using namespace std;

/*
	Problem : N이 주어졌을 때, 버린 카드들을 순서대로 출력하고, 마지막에 남게 되는 카드를 출력하는 프로그램을 작성
	Input : 정수 N (1 <= N <= 1000)
	Output : 버리는 카드들을 순서대로 출력 & 마지막에 남게 되는 카드의 번호 출력
*/

int main() {
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (true) {
		if (q.size() == 1) break;
		int discard = q.front();
		q.pop();
		cout << discard << " ";
		if (q.size() == 1) break;
		int cur = q.front();
		q.pop();
		q.push(cur);
	}
	cout << q.front();
	return 0;
}
