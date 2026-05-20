#include <iostream>
#include <string>
using namespace std;

// Step 3: Cai dat thuat toan duyet cay NLR, LNR, LRN
struct Node { string data; Node* left; Node* right; };
Node* CreateNode(string val) { Node* p = new Node; p->data = val; p->left = p->right = NULL; return p; }

void PreOrder(Node* root) {
    if (root != NULL) { cout << root->data << " "; PreOrder(root->left); PreOrder(root->right); }
}
void InOrder(Node* root) {
    if (root != NULL) { InOrder(root->left); cout << root->data << " "; InOrder(root->right); }
}
void PostOrder(Node* root) {
    if (root != NULL) { PostOrder(root->left); PostOrder(root->right); cout << root->data << " "; }
}

int main() {
    cout << "--- TRAVERSAL ALGORITHMS ADDED ---\n";
    return 0;
}