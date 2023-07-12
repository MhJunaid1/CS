#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = NULL;
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->key << " -> ";
            inorderTraversal(node->right);
        }
    }

    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        return node;
    }

    Node* findMinValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMinValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        return root;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorderTraversal() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.insert(8);
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(7);
    bst.insert(10);
    bst.insert(14);
    bst.insert(4);

    bst.inorderTraversal();

    bst.deleteNode(10);

    bst.inorderTraversal();

    return 0;
}

