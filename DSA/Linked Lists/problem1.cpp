#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
        Node* next;
        T value;
        Node(){
            next=nullptr;
        }    
        Node(T value){
            this->value=value;
            next=nullptr;
        }
};
Node* removeDuplicates(Node* head){
    Node *first=head;
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->value==temp->next->value){
            temp-next=temp->next->next;
            temp=temp->next->next;
        }
        else{
            temp=temp->next;
        }
        
    }
    return first;
}

template<typename T>
class SinglyLinkedList{
    private:
        Node* head;
    public:
        SinglyLinkedList(){
            head=nullptr;
        }
        void insert()

};
int main(){
    Node<int> obj(1);
    cout<<obj.value<<endl;
}