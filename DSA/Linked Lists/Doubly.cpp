#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot remove element.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* temp = head->next;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            temp->prev->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }
            delete temp;
        } else {
            std::cout << "Element not found in the list.\n";
        }
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << "\n";
    }
};

int main() {
    DoublyLinkedList doublyLinkedList;

    doublyLinkedList.insert(1);
    doublyLinkedList.insert(2);
    doublyLinkedList.insert(3);
    doublyLinkedList.insert(4);

    doublyLinkedList.displayForward();
    doublyLinkedList.displayBackward();

    doublyLinkedList.remove(3);
    doublyLinkedList.remove(5);

    doublyLinkedList.displayForward();
    doublyLinkedList.displayBackward();

    return 0;
}
