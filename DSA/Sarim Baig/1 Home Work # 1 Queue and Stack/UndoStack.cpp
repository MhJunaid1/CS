#include <iostream>

template <typename T>
class stack
{
private:
    T *arr;        // Pointer to be allocated
    int cap = 100; // Physical size
    int size;      // Logical size
    int top;
    int next(int i)
    {                         // utility function
        return (i + 1) % cap; // cap
    }

public:
    stack()
    {
        arr = new T[cap];
        size = 0;
        top = -1;
    }

    void push(const T &obj)
    {
        int top = next(top);
        arr[top] = obj;
        if (size != cap)
        {
            size++;
        }
    }

    void pop()
    {
        if (empty())
            return;

        top--;
        if (top < 0)
        {
            top = cap - 1;
        }
        if (size != cap)
        {
            size--;
        }
    }

    void printStack()
    {
        // Testing purposes
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }
    }

    const T &peek()
    { // Read only reference
        return arr[top];
    }

    bool empty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    // Destructor
    ~stack()
    {
        delete[] arr;
    }
};

int main()
{
    stack<int> stk1;
    stk1.push(22);
    stk1.push(33);
    stk1.push(44);
    stk1.push(55);
    stk1.push(66);

    stk1.printStack();
}
