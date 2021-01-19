#include <iostream>
#include <stack>

using namespace std;


Problem: 어떤 멜로디가 주어질 때, 손가락을 가장 적게 움직이는 경우의 수

Input : 음의 수 N, 프렛의 수 P, N개의 줄에 한 음을 나타내는 두 정수(num1, num2)

Output : 멜로디를 연주하는데 필요한 최소 손가락 움직이는 경우의 수(result)


int main(void)
{
	stack<int> n[7];
	int N, P, num1, num2, result = 0;
	cin >> N >> P;
	for (int i = 0; i < N; i++)
	{
		cin >> num1 >> num2;

		if (n[num1].empty())
		{
			n[num1].push(0);
		}

		if (num2 > n[num1].top())
		{
			result++;
			n[num1].push(num2);
		}

		else if (num2 < n[num1].top())
		{
			for (int k = i; k > 0; k--)
			{
				n[num1].pop();

				result++;

				if (num2 >= n[num1].top())
					break;
			}

			n[num1].push(num2);
			result++;
		}
	}

	cout << result << endl;

	return 0;
}
