#include <iostream>
#include <string>

using namespace std;

// --- CAU TRUC DU LIEU ---
struct File {
    string tenFile;
    int thoiGian;     // Timestamp de sap xep
    double kichThuoc; // Don vi: MB
};

struct Node {
    File data;
    Node* pNext;
};

struct SLL {
    Node* pHead;
    Node* pTail;
};

// --- CAC HAM XU LY ---
void initSLL(SLL* list) {
    list->pHead = list->pTail = NULL;
}

// 1. Them file theo thu tu thoi gian tang dan
void insertFile(SLL* list, File f) {
    Node* pNode = new Node{f, NULL};
    
    // Neu danh sach rong
    if (list->pHead == NULL) {
        list->pHead = list->pTail = pNode;
        return;
    }
    
    // Neu chen vao dau (thoi gian nho nhat)
    if (list->pHead->data.thoiGian > f.thoiGian) {
        pNode->pNext = list->pHead;
        list->pHead = pNode;
        return;
    }
    
    // Tim vi tri chen o giua hoac cuoi
    Node* cur = list->pHead;
    while (cur->pNext != NULL && cur->pNext->data.thoiGian <= f.thoiGian) {
        cur = cur->pNext;
    }
    
    pNode->pNext = cur->pNext;
    cur->pNext = pNode;
    
    // Cap nhat pTail neu chen vao cuoi cung
    if (pNode->pNext == NULL) list->pTail = pNode;
}

// 2. Tinh tong dung luong cac file hien co
double totalSize(SLL* list) {
    double sum = 0;
    for (Node* p = list->pHead; p != NULL; p = p->pNext) {
        sum += p->data.kichThuoc;
    }
    return sum;
}

// 3. Tim va xoa file co kich thuoc nho nhat
void removeSmallestFile(SLL* list) {
    if (list->pHead == NULL) return;

    Node *minNode = list->pHead, *prevMin = NULL;
    Node *cur = list->pHead, *prev = NULL;

    // Duyet tim node nho nhat
    while (cur != NULL) {
        if (cur->data.kichThuoc < minNode->data.kichThuoc) {
            minNode = cur;
            prevMin = prev;
        }
        prev = cur;
        cur = cur->pNext;
    }

    // Ngat lien ket
    if (prevMin == NULL) list->pHead = minNode->pNext;
    else prevMin->pNext = minNode->pNext;

    // Cap nhat pTail neu vua xoa node cuoi
    if (minNode == list->pTail) list->pTail = prevMin;
    if (list->pHead == NULL) list->pTail = NULL; // Xoa sach

    delete minNode;
}

// 4. Sao luu sang USB 32GB (32 * 1024 MB = 32768 MB)
void backupToUSB(SLL* list) {
    const double MAX_USB = 32768.0; 
    while (totalSize(list) > MAX_USB && list->pHead != NULL) {
        removeSmallestFile(list);
    }
}

// Ham phu tro in danh sach
void printList(SLL* list) {
    for (Node* p = list->pHead; p != NULL; p = p->pNext) {
        cout << p->data.tenFile << " | " << p->data.kichThuoc << "MB | Time: " << p->data.thoiGian << "\n";
    }
}

// --- CHUONG TRINH CHINH ---
int main() {
    SLL list;
    initSLL(&list);

    // Du lieu mau (Tong = 45000 MB > 32768 MB)
    insertFile(&list, {"File1.pdf", 3, 5000});
    insertFile(&list, {"File2.mp4", 1, 20000});
    insertFile(&list, {"File3.zip", 4, 20000});
    
    cout << "--- Danh sach hien tai ---\n";
    printList(&list);
    cout << "Tong dung luong: " << totalSize(&list) << " MB\n\n";

    cout << "--- Dang copy sang USB 32GB ---\n";
    backupToUSB(&list);
    
    printList(&list);
    cout << "Tong dung luong sau khi xoa bot: " << totalSize(&list) << " MB\n";

    return 0;
}
