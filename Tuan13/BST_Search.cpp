#include <iostream>
#include <vector>

using namespace std;

struct Node { int data; Node* left; Node* right; };
Node* createNode(int value) { Node* newNode = new Node(); newNode->data = value; newNode->left = NULL; newNode->right = NULL; return newNode; }

// Ham them Node vao BST (Quy tac: Trai <= Cha, Phai > Cha)
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value <= root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int main() { return 0; }