#include <iostream>
#include <string>
using namespace std;

// Cau truc Node cay nhi phan dung con tro
struct Node {
    string data; 
    Node* left;
    Node* right;
};

Node* CreateNode(string val) {
    Node* p = new Node;
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main() {
    cout << "=== TREE PRACTICE ===\n";
    return 0;
}