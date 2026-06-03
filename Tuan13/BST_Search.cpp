#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) return createNode(value);
    
    if (value <= root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Ham tim kiem kem tinh nang in ra vet duyet cay
Node* searchBST(Node* root, int target) {
    if (root == NULL) return NULL;
    
    cout << root->data;
    
    if (root->data == target) {
        cout << " (Da tim thay gtri can tim)\n";
        return root;
    }
    
    cout << " -> ";
    
    if (target <= root->data) {
        return searchBST(root->left, target);
    } else {
        return searchBST(root->right, target);
    }
}

int main() {
    Node* root = NULL;
    vector<int> years = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};
    
    for (int y : years) {
        root = insertNode(root, y);
    }
    
    int target = 2004;
    cout << "Trinh tu duyet cay: ";
    searchBST(root, target);
    
    return 0;
}