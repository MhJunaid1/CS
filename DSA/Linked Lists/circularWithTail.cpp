#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            tail->next = head;  // Make the list circular
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    list.display();

    return 0;
}
