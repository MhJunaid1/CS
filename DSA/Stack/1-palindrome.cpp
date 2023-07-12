#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool push(char x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return false;
        }
        else {
            arr[++top] = x;
            cout << x << " pushed to stack\n";
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else {
            char x = arr[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        else {
            char x = arr[top];
            return x;
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main(int argc,char* argv[]) {
    char *str = argv[1];

    cout<<str<<endl;
    int size = strlen(str),i=0,mid=0;
    Stack *s1,*s2;
    s1=new Stack();
    s2=new Stack();
    if(size%2==1){
        mid=size/2+1;
    }
    else{
        mid = size/2;
    }
    for(;i<mid;i++){
        s1->push(str[i]);
    }
    cout<<i<<endl;
    for(i=size-1;i>=size/2;i--){
        s2->push(str[i]);
    }
    bool res = true;
    for(i=0;i<size/2;i++){
        if(s1->pop()!=s2->pop()){
            res=false;
        }
    }
    if(res==true){
        cout<<"Pallindrome";
    }
    else{
        cout<<"Not";
    }

    return 0;
}


