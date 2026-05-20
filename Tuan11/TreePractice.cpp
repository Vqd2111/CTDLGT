#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Final Step: Code hoan chinh 100% bai tap ve nha Tuan 11
struct Node {
    string data; 
    Node* left; 
    Node* right;
};

Node* CreateNode(string val) {
    Node* p = new Node; 
    p->data = val; 
    p->left = p->right = NULL; 
    return p;
}

// 4 Cay dac biet dung con tro
Node* BuildFull() {
    Node* t = CreateNode("A");
    t->left = CreateNode("B"); t->right = CreateNode("C");
    t->left->left = CreateNode("D"); t->left->right = CreateNode("E");
    return t;
}
Node* BuildLeft() {
    Node* t = CreateNode("A"); t->left = CreateNode("B"); t->left->left = CreateNode("C"); return t;
}
Node* BuildRight() {
    Node* t = CreateNode("A"); t->right = CreateNode("B"); t->right->right = CreateNode("C"); return t;
}
Node* BuildZig() {
    Node* t = CreateNode("A"); t->left = CreateNode("B"); t->left->right = CreateNode("C"); return t;
}
Node* BuildExp() {
    Node* t = CreateNode("*");
    t->left = CreateNode("+"); t->right = CreateNode("-");
    t->left->left = CreateNode("5"); t->left->right = CreateNode("3");
    t->right->left = CreateNode("4"); t->right->right = CreateNode("2");
    return t;
}

// Cac ham duyet Con tro
void PreOrder(Node* root) {
    if (root != NULL) { cout << root->data << " "; PreOrder(root->left); PreOrder(root->right); }
}
void InOrder(Node* root) {
    if (root != NULL) {
        bool op = (root->data == "+" || root->data == "-" || root->data == "*" || root->data == "/");
        if (op) cout << "( ";
        InOrder(root->left); cout << root->data << " "; InOrder(root->right);
        if (op) cout << ") ";
    }
}
void PostOrder(Node* root) {
    if (root != NULL) { PostOrder(root->left); PostOrder(root->right); cout << root->data << " "; }
}

// Cac ham duyet Mang
void PreOrderArr(const vector<string>& arr, int idx) {
    if (idx < arr.size() && arr[idx] != "NULL") {
        cout << arr[idx] << " "; PreOrderArr(arr, 2 * idx + 1); PreOrderArr(arr, 2 * idx + 2);
    }
}
void InOrderArr(const vector<string>& arr, int idx) {
    if (idx < arr.size() && arr[idx] != "NULL") {
        string val = arr[idx]; bool op = (val == "+" || val == "-" || val == "*" || val == "/");
        if (op) cout << "( ";
        InOrderArr(arr, 2 * idx + 1); cout << val << " "; InOrderArr(arr, 2 * idx + 2);
        if (op) cout << ") ";
    }
}
void PostOrderArr(const vector<string>& arr, int idx) {
    if (idx < arr.size() && arr[idx] != "NULL") {
        PostOrderArr(arr, 2 * idx + 1); PostOrderArr(arr, 2 * idx + 2); cout << arr[idx] << " ";
    }
}

int main() {
    cout << "========================================================\n";
    cout << "   CAU TRUC 1: LUU TRU MOC NOI (SU DUNG CON TRO)\n";
    cout << "========================================================\n";
    Node* full = BuildFull();   cout << "+ Cay day du (Duyet truoc): "; PreOrder(full); cout << endl;
    Node* left = BuildLeft();   cout << "+ Cay lech trai (Duyet truoc): "; PreOrder(left); cout << endl;
    Node* right = BuildRight(); cout << "+ Cay lech phai (Duyet truoc): "; PreOrder(right); cout << endl;
    Node* zig = BuildZig();     cout << "+ Cay Zigzac (Duyet truoc): "; PreOrder(zig); cout << endl;
    
    Node* exp = BuildExp();
    cout << "\n* Cay bieu thuc (5 + 3) * (4 - 2):\n";
    cout << "  - Duyet truoc (Tien to): "; PreOrder(exp); cout << endl;
    cout << "  - Duyet giua  (Trung to): "; InOrder(exp); cout << endl;
    cout << "  - Duyet sau   (Hau to) : "; PostOrder(exp); cout << endl;

    cout << "\n========================================================\n";
    cout << "   CAU TRUC 2: LUU TRU TUAN TU (SU DUNG MANG 1 CHIEU)\n";
    cout << "========================================================\n";
    vector<string> aFull = {"A", "B", "C", "D", "E"};
    cout << "+ Cay day du (Duyet truoc): "; PreOrderArr(aFull, 0); cout << endl;
    vector<string> aLeft = {"A", "B", "NULL", "C", "NULL", "NULL", "NULL"};
    cout << "+ Cay lech trai (Duyet truoc): "; PreOrderArr(aLeft, 0); cout << endl;
    vector<string> aRight = {"A", "NULL", "B", "NULL", "NULL", "NULL", "C"};
    cout << "+ Cay lech phai (Duyet truoc): "; PreOrderArr(aRight, 0); cout << endl;
    vector<string> aZig = {"A", "B", "NULL", "NULL", "C"};
    cout << "+ Cay Zigzac (Duyet truoc): "; PreOrderArr(aZig, 0); cout << endl;
    
    vector<string> aExp = {"*", "+", "-", "5", "3", "4", "2"};
    cout << "\n* Cay bieu thuc tuan tu:\n";
    cout << "  - Duyet truoc (Tien to): "; PreOrderArr(aExp, 0); cout << endl;
    cout << "  - Duyet giua  (Trung to): "; InOrderArr(aExp, 0); cout << endl;
    cout << "  - Duyet sau   (Hau to) : "; PostOrderArr(aExp, 0); cout << endl;
    return 0;
}