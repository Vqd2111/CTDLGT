#include <iostream>
#include <chrono>
using namespace std;

// Cau truc cua 1 nguoi trong vong tron (Danh sach lien ket VONG)
struct Node {
    int id; 
    Node* next;
};

// Ham thuc thi tro choi chuyen bong: N nguoi, chuyen M lan
int FindWinner(int N, int M) {
    if (N <= 0) return 0;
    
    //KHOI TAO DANH SACH LIEN KET VONG (Circular SLL)
    
    Node* pHead = new Node; // Tao nguoi so 1 (Dau danh sach)
    pHead->id = 1;
    pHead->next = NULL;
    
    Node* p = pHead; // p la con tro chay de tao them cac nut moi
    
    // Tao tu nguoi so 2 den nguoi so N
    for (int i = 2; i <= N; i++) {
        Node* taoMoi = new Node;
        taoMoi->id = i;
        taoMoi->next = NULL;
        
        p->next = taoMoi; // Moc nguoi hien tai voi nguoi vua tao
        p = taoMoi;       // p di chuyen den nguoi vua tao
    }
    
    //Nguoi cuoi cung phai noi vong ve nguoi dau tien
    p->next = pHead; 
    
    //TRO CHOI LOAI TRU
    
    Node* q = pHead; // q dai dien cho nguoi dang cam bong
    Node* temp = p;  // temp dai dien cho nguoi ngoi ngay TRUOC q (luc bat dau thi temp la nguoi cuoi cung)
    
    // Vong lap sinh tu: Chay den khi nao nguoi ngoi canh q la chinh q -> Con lai 1 nguoi duy nhat
    while (q->next != q) {
        
        // Nhay bong M buoc
        for (int i = 0; i < M; i++) {
            temp = q;       // temp luon bam theo q
            q = q->next;    // q chuyen bong cho nguoi tiep theo
        }
        
        // Luc nay q la nguoi phai roi khoi vong tron. Can tien hanh xoa nut q.
        
        temp->next = q->next; // Nguoi dung truoc q se noi truc tiep voi nguoi dung sau q
        Node* nodeXoa = q;    // Giu lai dia chi cua q
        q = q->next;          // q ban giao bong cho nguoi tiep theo de choi vong moi
        
        delete nodeXoa;       // Thu hoi bo nho cua nguoi bi loai
    }
    
    // Vong lap dung lai, q la nguoi thang cuoc
    int ketQua = q->id;
    delete q; // Don dep not nut cuoi cung
    return ketQua;
}

int main() {
    cout << "--- BAI TOAN JOSEPHUS ---\n";
    cout << "Test 1: N = 5, M = 0 => Nguoi thang: " << FindWinner(5, 0) << endl;
    cout << "Test 2: N = 5, M = 1 => Nguoi thang: " << FindWinner(5, 1) << endl;
    
    // Test theo yeu cau 2: Tinh thoi gian chay voi N lon
    int N_lon = 100000;
    int M_test = 1; 
    cout << "\nDang chay thuat toan voi N = " << N_lon << ", M = " << M_test << " ...\n";
    
    // Bat dong ho
    auto start = chrono::high_resolution_clock::now();
    
    int nguoiThang = FindWinner(N_lon, M_test);
    
    // Tat dong ho
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> tgian = end - start;
    
    cout << "=> Nguoi song sot cuoi cung: " << nguoiThang << endl;
    cout << "=> Thoi gian hoan thanh: " << tgian.count() << " s\n";
    
    return 0;
}