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
        char str[] = "{([])}";
        
        int size = strlen(str),i=0;
        if(size%2==1){
            cout<<"Unbalanced"<<endl;
            return 0;
        }
        Stack s1,s2;
        for(;i<size/2;i++){
            s1.push(str[i]);
        }
        for(i=size-1;i>=size/2;i--){
            s2.push(str[i]);
        }
        bool res = true;
        while(s1.isEmpty()!=true && s2.isEmpty()!=true){
            char temp1,temp2;
            temp1=s1.pop();
            temp2=s2.pop();
            if((temp1 == '{' && temp2=='}')||(temp1 == '[' && temp2==']')||(temp1 == '(' && temp2==')')||(temp1 == '<' && temp2=='>')){
                res=true;
            }
            else{
                res=false;
                break;
                }
        }
        if(res==true){
            cout<<"Balanced"<<endl;
        }
        else{
            cout<<"Unbalanced"<<endl;
        }
  
    return 0;
}

