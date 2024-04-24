#include <iostream>
using namespace std;

template <typename T>
class EnhancedQueue
{
private:
	T *eqptr;
	int front;
	int rear;
	int n, cap;

	int next(int i)
	{
		return (i + 1) % cap;
	}

public:
	EnhancedQueue()
	{
		eqptr = nullptr;
		front = rear = -1;
		n = cap = 0;
	}

	EnhancedQueue(int icap)
	{
		eqptr = new T[icap];
		cap = icap;
		n = 0;
		front = rear = -1;
	}

	void enqueueAtFront(T &obj)
	{
		if (n == cap)
		{
			// Queue is full, resize the array
			resize(2 * cap);
		}
		if (empty())
		{
			front = rear = 0;
		}
		else
		{
			front = (front - 1 + cap) % cap;
		}
		eqptr[front] = obj;
		n++;
	}

	void dequeueAtFront()
	{
		if (empty())
			return;
		front = (front + 1) % cap;
		n--;
		if (n == 0)
		{
			front = rear = -1;
		}
		if (n == cap / 4 && cap > 1)
		{
			// Queue is quarter full, resize the array
			resize(cap / 2);
		}
	}

	void enqueueAtRear(T &obj)
	{
		if (n == cap)
		{
			// Queue is full, resize the array
			resize(2 * cap);
		}
		if (empty())
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % cap;
		}
		eqptr[rear] = obj;
		n++;
	}

	void dequeueAtRear()
	{
		if (empty())
			return;
		rear = (rear - 1 + cap) % cap;
		n--;
		if (n == 0)
		{
			front = rear = -1;
		}
		if (n == cap / 4 && cap > 1)
		{
			// Queue is quarter full, resize the array
			resize(cap / 2);
		}
	}

	T peekFront()
	{
		if (empty())
			throw runtime_error("Queue is empty");
		return eqptr[front];
	}

	T peekRear()
	{
		if (empty())
			throw runtime_error("Queue is empty");
		return eqptr[rear];
	}

	int size()
	{
		return n;
	}

	bool empty()
	{
		return n == 0;
	}

	void resize(int newCap)
	{
		T *newArr = new T[newCap];
		for (int i = 0; i < n; i++)
		{
			newArr[i] = eqptr[(front + i) % cap];
		}
		delete[] eqptr;
		eqptr = newArr;
		cap = newCap;
		front = 0;
		rear = n - 1;
	}
};

int main()
{
	EnhancedQueue<int> eq(5); // Create an EnhancedQueue object with capacity 5

	// Enqueue two elements at the rear
	int value1 = 10;
	int value2 = 20;
	eq.enqueueAtRear(value1);
	eq.enqueueAtRear(value2);

	// Enqueue one element at the front
	int value3 = 5;
	eq.enqueueAtFront(value3);

	// Display the contents of the queue
	cout << "Queue size: " << eq.size() << endl;
	cout << "Front element: " << eq.peekFront() << endl;
	cout << "Rear element: " << eq.peekRear() << endl;

	return 0;
}

/*

Problem 1 “Enhanced Queue”
Implement a C++ class with the following definition:
template <typename T>
class EnhancedQueue{
private:
//Only the following members are allowed
T * eqptr;
int front;
int rear;
int n, cap;
//you can add utility methods here
public:
EnhancedQueue();
void enqueueAtFront(T & obj);
void dequeueAtFront();
void enqueueAtRear(T & obj);
void dequeueAtRear();
T peekFront();
T peekRear();
int size();
bool empty();
}


As you can guess from this definition, the EnhancedQueue allows enqueues and dequeues at both the
front and rear of the queue. This means that elements can be added at the front or the rear of the
queue as well as removed from the front or the rear using one of the four enqueue/dequeue methods.
It’s also evident from the code above that you are only using a single dynamically allocated array for this
purpose. Just like the ordinary queue, this queue needs to be circular to save space. When the space fills
up, the capacity of the array should be doubled. When more than half of the array becomes empty, the
size of the array should be reduced by one-half.


*/