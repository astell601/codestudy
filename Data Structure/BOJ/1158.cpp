#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

/*
	Problem : K번째 사람이 N번 제거되는 순서인 요세푸스 순열을 구하자
	Input : 정수 N, K
	Output : 요세푸스 순열
*/

int main(void)
{
	int N, K;
	cin >> N >> K;
	queue<int> q, r;
	
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	for (int p = 0; p < N; p++)
	{
		for (int k = 1; k <= K; k++)
		{
		
			if (k == K)
			{
				r.push(q.front());
				q.pop();
			}

			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
	
	cout << "<";

	for (int j = 0; j < N; j++)
	{
		cout << r.front();
		if (j == N - 1)
			break;
		else
			cout << "," << " ";
		r.pop();

	}
	cout << ">" << endl;

	return 0;
}
