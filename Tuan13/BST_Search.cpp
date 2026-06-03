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

int main() {
    Node* root = NULL;
    vector<int> years = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};
    
    for (int y : years) {
        root = insertNode(root, y);
    }
    cout << "--- DA NAP DU LIEU NAM SINH VAO CAY ---\n";
    return 0;
}