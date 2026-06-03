#include <iostream>
#include <vector>

using namespace std;

// Cau truc Node cho Cay nhi phan tim kiem (BST)
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Ham khoi tao Node moi
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    cout << "--- KHOI TAO DU AN CAY NHI PHAN TIM KIEM (BST) ---\n";
    return 0;
}