#include <iostream>
#include <string>
using namespace std;

// Step 2: Them cac ham tao 4 cay dac biet
struct Node { string data; Node* left; Node* right; };
Node* CreateNode(string val) { Node* p = new Node; p->data = val; p->left = p->right = NULL; return p; }

Node* BuildFull() {
    Node* t = CreateNode("A"); t->left = CreateNode("B"); t->right = CreateNode("C"); return t;
}
Node* BuildLeft() {
    Node* t = CreateNode("A"); t->left = CreateNode("B"); return t;
}
Node* BuildRight() {
    Node* t = CreateNode("A"); t->right = CreateNode("B"); return t;
}
Node* BuildZig() {
    Node* t = CreateNode("A"); t->left = CreateNode("B"); t->left->right = CreateNode("C"); return t;
}

int main() {
    cout << "--- LINKED LIST TREE BUILD SUCCESS ---\n";
    return 0;
}