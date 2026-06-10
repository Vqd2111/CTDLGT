#include <iostream>
#include <algorithm>
using namespace std;

struct Node { int data; Node* left; Node* right; int height; };
int getHeight(Node* node) { if (node == NULL) return 0; return node->height; }
Node* rightRotate(Node* y) { Node* x = y->left; Node* T2 = x->right; x->right = y; y->left = T2; y->height = max(getHeight(y->left), getHeight(y->right)) + 1; x->height = max(getHeight(x->left), getHeight(x->right)) + 1; return x; }
Node* leftRotate(Node* x) { Node* y = x->right; Node* T2 = y->left; y->left = x; x->right = T2; x->height = max(getHeight(x->left), getHeight(x->right)) + 1; y->height = max(getHeight(y->left), getHeight(y->right)) + 1; return y; }
int getBalanceFactor(Node* node) { if (node == NULL) return 0; return getHeight(node->left) - getHeight(node->right); }

Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1; 
    return node;
}

// Thuat toan chen Node can bang AVL
Node* insertNode(Node* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->data) node->left = insertNode(node->left, value);
    else if (value > node->data) node->right = insertNode(node->right, value);
    else return node; // Khong nhan gia tri trung lap

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    // Case 1: Left Left (LL)
    if (balance > 1 && value < node->left->data) return rightRotate(node);

    // Case 2: Right Right (RR)
    if (balance < -1 && value > node->right->data) return leftRotate(node);

    // Case 3: Left Right (LR)
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL)
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() { return 0; }