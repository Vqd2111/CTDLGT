#include <iostream>
#include <vector>
using namespace std;

struct Node { int data; Node* left; Node* right; };
Node* createNode(int value) { Node* newNode = new Node(); newNode->data = value; newNode->left = NULL; newNode->right = NULL; return newNode; }
Node* insertNode(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value <= root->data) root->left = insertNode(root->left, value);
    else root->right = insertNode(root->right, value);
    return root;
}
void inOrder(Node* root) {
    if (root != NULL) { inOrder(root->left); cout << root->data << " "; inOrder(root->right); }
}

// Ham tim kiem tren BST
Node* searchBST(Node* root, int target) {
    if (root == NULL || root->data == target) return root;
    if (target <= root->data) return searchBST(root->left, target);
    return searchBST(root->right, target);
}

int main() { return 0; }