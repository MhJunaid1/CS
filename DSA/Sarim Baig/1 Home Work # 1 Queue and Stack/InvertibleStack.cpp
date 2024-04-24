#include <iostream>

#include <iostream>

template <typename T>
class CircularStack
{
private:
    T *stackArray;
    int capacity;
    int top;
    bool flipBit;

public:
    CircularStack(int initialCapacity = 10)
    {
        stackArray = new T[initialCapacity];
        capacity = initialCapacity;
        top = -1;
        flipBit = false;
    }

    ~CircularStack()
    {
        delete[] stackArray;
    }

    void push(const T &element)
    {
        if (flipBit)
        {
            // Invert the push operation if stack is flipped
            if (top == -1)
            {
                top = capacity - 1;
            }
            else
            {
                top = (top - 1 + capacity) % capacity;
            }
            stackArray[top] = element;
        }
        else
        {
            // Normal push operation
            top = (top + 1) % capacity;
            stackArray[top] = element;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow." << std::endl;
            return;
        }
        // Invert the pop operation if stack is flipped
        if (flipBit)
        {
            if (top == capacity - 1)
            {
                top = -1;
            }
            else
            {
                top = (top + 1) % capacity;
            }
        }
        top = (top - 1 + capacity) % capacity;
    }

    T peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return T();
        }
        return stackArray[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void flipStack()
    {
        flipBit = !flipBit;
    }
};

int main()
{
    CircularStack<int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.flipStack();

    std::cout << "Elements after flipping: ";
    while (!stack.isEmpty())
    {
        std::cout << stack.peek() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}

/*
Problem 2 “Invertible Stack”
Add the following methodology to the Stack Class written in the lecture on Stack:
Add a method called flipStack. This method should work in O(1). Its effect should be such that the whole
stack should be logically inverted, i.e. the oldest element becomes the newest and vice versa. So the
next pop will remove the element that was at the bottom of the stack before it had been flipped. Notice
that the stack may be flipped again and again by using the flipStack method repeatedly. Make sure that
no slot of the array is wasted (Hint: Circular). As always, when the stack fills up we double its capacity;
and when more than half of it is empty, we halve the capacity.
*/