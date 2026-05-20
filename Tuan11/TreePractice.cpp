#include <iostream>
#include <string>
using namespace std;

// Step 4: Toi uu ham InOrder de tu dong them dau ngoac bieu thuc
struct Node { string data; Node* left; Node* right; };
Node* CreateNode(string val) { Node* p = new Node; p->data = val; p->left = p->right = NULL; return p; }

void InOrder(Node* root) {
    if (root != NULL) {
        bool op = (root->data == "+" || root->data == "-" || root->data == "*" || root->data == "/");
        if (op) cout << "( ";
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
        if (op) cout << ") ";
    }
}

int main() {
    cout << "--- FIXED EXPRESSION INORDER FORMAT ---\n";
    return 0;
}