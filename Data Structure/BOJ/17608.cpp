#include <iostream>
using namespace std;


	Problem : N개의 막대기에 대한 높이 정보가 주어질 때, 오른쪽에서 보아서 몇 개가 보이는지를 알아내는 프로그램 작성
	Input : 막대기의 개수 N, 막대기의 높이 h
	Output : 오른쪽에서 N개의 막대기를 보았을 때, 보이는 막대기의 갯수


int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

template <class T>
class Stack
{// 0개 이상의 원소를 가진 유한 순서 리스트
private:
	T* stack;		// 스택 원소를 위한 배열
	int top;		// 톱 원소의 위치
	int capacity;	// 스택 배열의 크기

public:
	Stack(int stackCapacity = 10);
	// 처음에 크기가 stackCapacity인 공백 스택을 생성
	
	T& Top() const;
	// 스택의 톱 원소를 반환

	int Push(const T& item);
	// 스택의 톱에 item을 삽입

	int Pop();
	// 스택의 톱 원소를 삭제 & 비교를 위해 값 반환

};

template <class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity), top(-1)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
T& Stack<T>::Top() const
{
	//if (IsEmpty()) throw "Stack is empty";

	
	if (top == -1)
		cout << top << endl;
	else
		cout << stack[top] << endl;
	
	return stack[top];
}


template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >=0";
	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[]a;
	a = temp;
}

template <class T>
int Stack<T>::Push(const T& x)
{
	// 스택에 x를 삽입한다.
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
	return top;

}

template <class T>
int Stack<T>::Pop()
{
	// 스택에서 원소를 삭제한다.
	//if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	
	if (top == -1)
		cout << top << endl;
	else
	{
		//cout << stack[top] << endl;
		stack[--top].~T(); // T에 대한 파괴자

	}
	
	return stack[top];
}


int main(void)
{
	int num, stick = 1, standard;
	cin >> num;
	Stack<int> data;

	for (int i = 0; i < num; i++)
	{
		int height;
		cin >> height;
		data.Push(height);
	}
	
	standard = data.Top();

	while (standard)
	{
		if (standard >= data.Pop())
		{
			stick;
		}
		else
			stick++;
	}

	
	for (int k = 0; k < num; k++)
	{
		if (standard >= data.Pop())
		{
			stick;
		}
		else
			stick++;
	}

	cout << stick << endl;

	return 0;
}
