#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
class Queue
{// 0개 이상의 원소를 가진 유한 순서 리스트

private:
	T* queue;			// 큐 원소를 위한 배열
	int front,			// 첫 번째 원소로부터 반시계 방향으로 한 위치 뒤
		rear,			// 마지막 원소의 위치
		capacity;		// 큐 배열의 크기

public:
	Queue(int queueCapacity = 10);
	// 처음에 크기가 queueCapacity인 공백 큐를 생성

	bool IsEmpty();
	// 큐의 원소 수가 0이면 true, 아니면 false를 반환

	T& Front();
	// 큐의 앞에 있는 원소를 반환

	T& Rear();
	// 큐의 뒤에 있는 원소를 반환

	void Push(const T& item);
	// 큐의 뒤에 item을 삽입

	void Pop();
	// 큐의 앞 원소를 삭제
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() { return front == rear; }

template <class T>
inline T& Queue<T>::Front()
{
	if (IsEmpty())throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
	if (IsEmpty())throw "Queue is empty. No rear element";
	return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& x)
{// 큐의 리어에 x를 삽입한다.
	if ((rear + 1) % capacity == front)
	{// 큐가 만원이면 크기를 두 배로
	
		// 두 배 크기의 배열을 할당
		T* newQueue = new T[2 * capacity];

		// queue를 newQueue로 복사
		int start = (front + 1) % capacity;
		if (start < 2)
		{
			// 둘러쌀 필요가 없음
			copy(queue + start, queue + start + capacity, newQueue);
		}

		else
		{
			// 둘러싸서 큐를 만듦
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);

		}

		// newQueue로 전환
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[]queue;
		queue = newQueue;

	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template <class T>
void Queue<T>::Pop()
{// 큐로부터 원소를 삭제한다.
	if (IsEmpty())throw "Queue is empty. Cannot delete.";
	front = (front + 1) % capacity;
	queue[front].~T(); // T를 위한 파괴자
}


int main(void)
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);

	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	
	q.Pop();

	cout << q.Front() << endl;
	cout << q.Rear() << endl;

	q.Pop();

	cout << q.Front() << endl;
	cout << q.Rear() << endl;

	return 0;
}
