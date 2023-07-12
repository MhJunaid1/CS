#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> stack1; // For enqueue operation
    std::stack<int> stack2; // For dequeue operation

public:
    void enqueue(int x) {
        // Move all elements from stack2 to stack1
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }

        // Push the new element onto stack1
        stack1.push(x);
    }

    int dequeue() {
        // If both stacks are empty, the queue is empty
        if (stack1.empty() && stack2.empty()) {
            std::cout << "Queue is empty. Cannot dequeue element.\n";
            return -1;
        }

        // If stack2 is empty, transfer elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Pop the top element from stack2 (which is the oldest element in the queue)
        int dequeuedValue = stack2.top();
        stack2.pop();

        return dequeuedValue;
    }

    bool isEmpty() {
        return (stack1.empty() && stack2.empty());
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeued element: " << queue.dequeue() << "\n";
    std::cout << "Dequeued element: " << queue.dequeue() << "\n";

    queue.enqueue(4);

    std::cout << "Dequeued element: " << queue.dequeue() << "\n";
    std::cout << "Dequeued element: " << queue.dequeue() << "\n";

    if (queue.isEmpty()) {
        std::cout << "Queue is empty\n";
    } else {
        std::cout << "Queue is not empty\n";
    }

    return 0;
}
