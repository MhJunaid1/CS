#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> queue1; // Main queue for stack operations
    std::queue<int> queue2; // Auxiliary queue for stack operations

public:
    void push(int x) {
        // Move all elements from queue1 to queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // Push the new element onto queue1
        queue1.push(x);

        // Move all elements back to queue1 from queue2
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop element.\n";
            return -1;
        }

        int poppedValue = queue1.front();
        queue1.pop();
        return poppedValue;
    }

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot get top element.\n";
            return -1;
        }

        return queue1.front();
    }

    bool isEmpty() {
        return queue1.empty();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << "\n";

    std::cout << "Popped element: " << stack.pop() << "\n";
    std::cout << "Popped element: " << stack.pop() << "\n";

    std::cout << "Top element: " << stack.top() << "\n";

    stack.push(4);

    std::cout << "Top element: " << stack.top() << "\n";

    return 0;
}
