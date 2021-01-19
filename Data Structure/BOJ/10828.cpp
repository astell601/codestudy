#include <iostream>
#include <cstring>
using namespace std;

/
Problem : 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램 작성

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

Input :				Output :
14					
push 1				
push 2				
top					2
size				2
empty				0
pop					2
pop					1
pop					-1
size				0
empty				1
pop					-1
push 3
empty				0
top					3 

/

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

	void IsEmpty();
	// 스택의 원소 수가 0이면  true, 아니면 false를 반환

	T& Top() const;
	// 스택의 톱 원소를 반환

	int Size();
	// 스택에 들어 있는 정수의 개수를 출력

	int Push(const T& item);
	// 스택의 톱에 item을 삽입

	void Pop();
	// 스택의 톱 원소를 삭제

	void Command();
	// 명령을 입력받아 함수 템플릿과 연결시켜 출력
};

template <class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity), top(-1)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline void Stack<T>::IsEmpty() 
{ 
	if (top == -1)
		cout << "1" << endl;
	else
		cout << "0" << endl;
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
int Stack<T>::Size()
{
	int size = 0;
	for (int i = top; i >= 0; i--)
	{
		size++;
	}
	cout << size << endl;
	return size;
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
void Stack<T>::Pop()
{
	// 스택에서 원소를 삭제한다.
	//if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	if (top == -1)
		cout << top << endl;
	else
	{
		cout << stack[top] << endl;
		stack[--top].~T(); // T에 대한 파괴자
		
	}
}


int main(void)
{
	int num;
	cin >> num;
	Stack<int> data;

	for (int i = 0; i < num; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			data.Push(num);
		}

		else if (str == "pop")
			data.Pop();

		else if (str == "size")
			data.Size();

		else if (str == "empty")
			data.IsEmpty();

		else if (str == "top")
			data.Top();

		else
			cout << "Wrong command. Please try again." << endl;
	}
	
	return 0;
}
