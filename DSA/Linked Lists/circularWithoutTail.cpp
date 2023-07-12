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

public:
    CircularLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(int value) { //insertion at head
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;  // Make the list circular
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;  // Update head to the newly inserted node
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head->next;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head->next);
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
