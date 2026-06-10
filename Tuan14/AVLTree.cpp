#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* insertNode(Node* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->data) node->left = insertNode(node->left, value);
    else if (value > node->data) node->right = insertNode(node->right, value);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1 && value < node->left->data) return rightRotate(node);
    if (balance < -1 && value > node->right->data) return leftRotate(node);
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    cout << "=== BAI TAP TUAN 14: CAY CAN BANG AVL ===\n\n";
    Node* root = NULL;
    
    // Day so dau vao tu de bai Tuan 14
    vector<int> inputs = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    
    cout << "-> Tien hanh them cac phan tu vao cay AVL:\n";
    for (int x : inputs) {
        root = insertNode(root, x);
    }
    cout << "Da dung xong cay AVL tu dong can bang!\n\n";
    
    // In ket qua duyet cay 
    cout << "1. Ket qua duyet theo thu tu Truoc (Pre-order):\n[ ";
    preOrder(root);
    cout << "]\n\n";
    
    cout << "2. Ket qua duyet theo thu tu Giua (In-order):\n[ ";
    inOrder(root);
    cout << "]\n";
    
    return 0;
}