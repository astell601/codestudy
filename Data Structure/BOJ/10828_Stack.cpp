#include<iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	stack<int> s;
	int num;
	cin >> num;

	while (num--)
	{
		string command;
		int pnum;
		cin >> command;
		if (command == "push")
		{
			cin >> pnum;
			s.push(pnum);
			continue;
		}
		if (command == "pop")
		{
			if (s.empty())
				cout << "-1" << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (command == "size")
		{
			cout << s.size() << endl;
		}
		else if (command == "empty")
		{
			if (s.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (command == "top")
		{
			if (s.empty())
				cout << "-1" << endl;
			else
				cout << s.top() << endl;
		}
		else
			s.push((int)command[4]);
	}
}
