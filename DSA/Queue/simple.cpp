#include <iostream>

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = x;
        std::cout << x << " enqueued to the queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue element.\n";
            return -1;
        }

        int dequeuedValue = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }

        return dequeuedValue;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot peek element.\n";
            return -1;
        }

        return arr[front];
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.peek() << "\n";

    std::cout << queue.dequeue() << " dequeued from the queue.\n";
    std::cout << queue.dequeue() << " dequeued from the queue.\n";

    std::cout << "Front element: " << queue.peek() << "\n";

    queue.enqueue(4);

    std::cout << "Front element: " << queue.peek() << "\n";

    return 0;
}
