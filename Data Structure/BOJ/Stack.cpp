
	T* stack;		// 스택 원소를 위한 배열
	int top;		// 톱 원소의 위치
	int capacity;	// 스택 배열의 크기

public:
	Stack(int stackCapacity = 10);
	// 처음에 크기가 stackCapacity인 공백 스택을 생성

	bool IsEmpty() const;
	// 스택의 원소 수가 0이면  true, 아니면 false를 반환

	T& Top() const;
	// 스택의 톱 원소를 반환

	void Push(const T& item);
	// 스택의 톱에 item을 삽입

	void Pop();
	// 스택의 톱 원소를 삭제

	void PrintStack();
	// 스택에 저장된 값 모두 출력
};

template <class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const
{
	if (IsEmpty()) throw "Stack is empty";
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
void Stack<T>::Push(const T& x)
{
	// 스택에 x를 삽입한다.
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
	
}

template <class T>
void Stack<T>::PrintStack()
{
	for (int i = 0; i < capacity; i++) 
	{
		cout << stack[i] << endl;
	}
}

template <class T>
void Stack<T>::Pop()
{
	// 스택에서 원소를 삭제한다.
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T(); // T에 대한 파괴자
}


int main(void)
{
	Stack<int> data;
	data.Push(6);
	data.Push(1);
	data.Push(601);
	data.Push(2000);
	data.Push('A');
	data.Push('B');
	data.Push('C');
	data.Push('D');
	data.Push('E');
	data.Pop();
	data.PrintStack();
	
	return 0;
}
