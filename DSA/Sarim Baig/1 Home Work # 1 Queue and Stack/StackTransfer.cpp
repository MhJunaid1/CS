#include <iostream>

template <typename T>
class stack
{
private:
    T *arr;   // Pointer to be allocated
    int cap;  // Physical size
    int size; // Logical size
    int top;

public:
    stack(int icap = 0)
    {
        if (icap > 0)
        {
            arr = new T[icap];
            cap = icap;
        }
        else
        { // Default behaviour
            arr = nullptr;
            cap = 0;
        }
        size = 0;
        top = -1;
    }

    void push(const T &obj)
    {
        // Is the stack full (physically)
        if (size >= cap)
        {
            // Array is full, so grow it
            T *temp = new T[cap * 2];
            // Copy data from the older array
            for (int i = 0; i < size; ++i)
            {
                temp[i] = arr[i];
            }
            top = size;
            temp[++top] = obj;
            cap *= 2;
            size++;
            delete[] arr;
            arr = temp;
        }
        else if (cap == 0)
        {
            // What should we do?
            arr = new T[2];
            top = 0;
            arr[0] = obj;
            size = 1;
            cap = 2;
        }
        else
        {
            // There is a slot available
            arr[++top] = obj;
            size++;
        }
    }

    void pop()
    {
        if (empty())
            return;

        if ((size) == cap / 2)
        {
            // Array is half empty, so shrink it
            T *temp = new T[cap / 2];
            // Copy data from the older array
            for (int i = 0; i < size; ++i)
            {
                temp[i] = arr[i];
            }
            top = size;

            cap /= 2;
            top--;
            size--;
            delete[] arr;
            arr = temp;
        }
        else
        {
            top--;
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

    // Copy constructor
    stack(const stack &obj)
    {
        if (this == &obj)
        {
            return;
        }
        cap = obj.cap;
        arr = new T[cap];
        top = obj.top;
        size = obj.size;
        for (int i = 0; i < size; ++i)
        {
            arr[i] = obj.arr[i];
        }
    }

    // Assignment operator
    void operator=(const stack &obj)
    {
        if (this == &obj)
        {
            return;
        }
        cap = obj.cap;
        delete[] arr;
        arr = new T[cap];
        top = obj.top;
        size = obj.size;
        for (int i = 0; i < size; ++i)
        {
            arr[i] = obj.arr[i];
        }
    }

    // stack transfer
    void StackTransfer1(stack s, stack t)
    {
        stack<T> tempStack;
        while (!s.empty())
        {
            tempStack.push(s.peek());
            s.pop();
        }
        while (!tempStack.empty())
        {
            t.push(tempStack.peek());
            tempStack.pop();
        }
    }
    void stackTransfer2(stack s, stack t)
    {
        // store them in an array
        // and iterate over the array from the last of the array to start
    }
};

int main()
{
    stack<int> s(5); // Make a stack with cap=2
    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);
    s.push(66);

    stack<int> t(5);
    s.StackTransfer1(s, t);
    t.printStack();
}
