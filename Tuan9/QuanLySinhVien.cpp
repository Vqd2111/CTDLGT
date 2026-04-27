#include <iostream>
#include <string.h> 
using namespace std;

//Dinh nghia cau truc du lieu 
struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh; 
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

// Cau truc 1 Node cua Danh sach lien ket don (Singly Linked List)
struct Node {
    SinhVien data; // Du lieu cua Node
    Node *link;    // Con tro chua dia chi cua Node tiep theo
};

// Cau truc quan ly Danh sach
struct List {
    Node *first; // Con tro luon tro vao phan tu dau tien
    Node *last;  // Con tro luon tro vao phan tu cuoi cung
};

//Cac ham co ban

// Ham khoi tao danh sach rong
void Init(List &l) {
    l.first = NULL;
    l.last = NULL;
}

// Ham cap phat bo nho cho 1 Node moi va gan du lieu
Node* CreateNode(SinhVien x) {
    Node* p = new Node; // Xin he dieu hanh cap phat vung nho
    p->data = x;
    p->link = NULL;     // Node moi chua lien ket voi ai nen cho tro den NULL
    return p;
}

// Ham chen phan tu vao danh sach sao cho van giu duoc thu tu tang dan cua MaSV
void InsertSorted(List &l, SinhVien x) {
    Node* p = CreateNode(x);
    
    // Truong hop 1: Danh sach dang rong, p tro thanh nut duy nhat
    if (l.first == NULL) {
        l.first = l.last = p;
        return;
    }
    
    // Truong hop 2: Kiem tra xem maSV cua x co be hon nguoi dung dau danh sach khong.
    // Ham strcmp tra ve < 0 neu tham so 1 dung truoc tham so 2 trong bang chu cai.
    if (strcmp(x.maSV, l.first->data.maSV) < 0) {
        p->link = l.first; // Moc p vao dung truoc nut first hien tai
        l.first = p;       // Cap nhat lai first la p
        return;
    }
    
    // Truong hop 3: Duyet danh sach de tim vi tri chen thich hop (o giua hoac o cuoi)
    Node* q = l.first;   
    Node* temp = NULL;   
    
    // Chay vong lap den khi nao gap nut co maSV lon hon maSV cua x thi dung lai
    while (q != NULL && strcmp(q->data.maSV, x.maSV) < 0) {
        temp = q;
        q = q->link;
    }
    
    //da tim duoc vi tri: can chen p vao giua temp va q
    temp->link = p;
    p->link = q;    
    
    // Neu q chay den NULL,cap nhat l.last
    if (q == NULL) {
        l.last = p;
    }
}

// Ham in danh sach
void PrintList(List l) {
    Node* p = l.first;
    while (p != NULL) {
        cout << p->data.maSV << " | " << p->data.hoTen 
             << " | " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
        p = p->link; // Tien len nut tiep theo
    }
}

// Ham phu tro: So sanh 2 struct Ngay
int CheckDate(Ngay a, Ngay b) {
    if (a.ngay == b.ngay && a.thang == b.thang && a.nam == b.nam) return 1;
    return 0;
}

// Ham in ra cac sinh vien co cung ngay sinh (Thuat toan Quet cap)
void PrintDuplicates(List l) {
    int coTrung = 0; // Bien co (flag) de xac nhan co ket qua hay khong
    Node* p = l.first;
    
    cout << "\nDanh sach SV trung ngay sinh:\n";
    
    // p duyet tu dau den sat cuoi
    while (p != NULL && p->link != NULL) {
        Node* q = p->link; // q luon bat dau kiem tra tu nut dung sau p
        
        // q duyet tu sau p den cuoi danh sach
        while (q != NULL) {
            if (CheckDate(p->data.ngaySinh, q->data.ngaySinh)) {
                cout << "- " << p->data.hoTen << " trung voi " << q->data.hoTen << endl;
                coTrung = 1;
            }
            q = q->link;
        }
        p = p->link;
    }
    
    if (coTrung == 0) cout << "khong tim thay sinh vien cung ngay sinh\n";
}

// Ham xoa cac nut bi trung ngay sinh (Giu lai nut p, xoa nut q phia sau)
void RemoveDuplicates(List &l) {
    Node* p = l.first;
    
    while (p != NULL && p->link != NULL) {
        Node* temp = p;    // temp chay sau q, dung de ngat ket noi khi xoa
        Node* q = p->link; // 
        
        while (q != NULL) {
            // Neu phat hien q trung ngay sinh voi p -> tien hanh xoa q
            if (CheckDate(p->data.ngaySinh, q->data.ngaySinh)) {
                
                temp->link = q->link; 
                Node* nodeXoa = q;    
                q = q->link;          
                delete nodeXoa;       
                
            } else {
                // Neu q khong trung, cho ca temp va q tien len 1 buoc
                temp = q;
                q = q->link;
            }
        }
        p = p->link;
    }
}

int main() {
    List ds;
    Init(ds);
    
    // Tao du lieu gia lap de kiem thu
    SinhVien sv1 = {"SV005", "Nguyen Van A", 1, {1, 1, 2004}, "HN", "ET1", "DTVT"};
    SinhVien sv2 = {"SV001", "Le Thi B", 0, {1, 1, 2004}, "HP", "ET1", "DTVT"}; 
    SinhVien sv3 = {"SV003", "Tran Van C", 1, {15, 8, 2004}, "DN", "ET2", "DTVT"};
    SinhVien sv4 = {"SV002", "Hoang Thi D", 0, {20, 10, 2004}, "HCM", "ET2", "DTVT"};
    
    // Test ham chen giu nguyen thu tu
    InsertSorted(ds, sv1);
    InsertSorted(ds, sv2);
    InsertSorted(ds, sv3);
    InsertSorted(ds, sv4);
    
    cout << "--- DANH SACH LOP (Da sap xep) ---\n";
    PrintList(ds);
    
    PrintDuplicates(ds);
    
    cout << "\n--- DS SAU KHI LOC NGUOI TRUNG ---\n";
    RemoveDuplicates(ds);
    PrintList(ds);
    
    return 0;
}