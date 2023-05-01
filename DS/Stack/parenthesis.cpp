//Parenthesis optimal code using one stack
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

    int size() {
        return (top + 1);
    }
};

int main(int argc,char* argv[]) {
    char str[] = "{([ ])}";
    int size = strlen(str),i=0;
    Stack s;

    for(;i<size;i++){
        if(str[i] == '{'||str[i] == '['||str[i] == '<'||str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == '}'||str[i] == ']'||str[i] == '>'||str[i] == ')'){
            if(s.isEmpty()){
                cout<<"Unbalanced"<<endl;
                return 0;
            }
            char temp = s.pop();
            if((temp == '{' && str[i]=='}')||(temp == '[' && str[i]==']')||(temp == '(' && str[i]==')')||(temp == '<' && str[i]=='>')){
                cout<<"Matching: "<<temp<<" "<<str[i]<<endl;
            }
            else{
                cout<<"Not matching: "<<temp<<" "<<str[i]<<endl;
                return 0;
            }
        }
    }

    if(s.isEmpty()){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
  
    return 0;
}
