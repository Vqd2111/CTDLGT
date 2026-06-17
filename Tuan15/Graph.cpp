#include <iostream>
#include <string>

using namespace std;

// 1. KHAI BAO CAC HANG SO VA TEN TINH THANH
const int SO_DINH = 11;
const char* TEN_TINH[SO_DINH] = {"Ha Noi", "Thai Nguyen", "Bac Ninh", "Bac Giang", "Uong Bi", "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay"};

// 2. CAU TRUC HANG DOI TU DINH NGHIA (QUEUE)
struct HangDoi {
    int mangLuuTru[SO_DINH + 5];
    int dau, cuoi;

    void khoiTao() {
        dau = 0;
        cuoi = 0;
    }

    bool laRong() {
        return dau == cuoi;
    }

    void themVao(int giaTri) {
        mangLuuTru[cuoi++] = giaTri;
    }

    int layRa() {
        return mangLuuTru[dau++];
    }
};

// 3. CAU TRUC NUT CHO DANH SACH LIEN KET
struct NutLienKet {
    int maSoDinh;
    NutLienKet* tiepTheo;
};

// 4. CAU TRUC LUU TRU TUYEN DUONG
struct TuyenDuong {
    int tinh_U;
    int tinh_V;
};

// 5. THUAT TOAN BFS CHO MA TRAN KE
void duyetBFS_MaTran(int batDau, int maTranKe[SO_DINH][SO_DINH]) {
    bool daTham[SO_DINH] = {false};
    HangDoi hd;
    hd.khoiTao();

    daTham[batDau] = true;
    hd.themVao(batDau);

    cout << "Ket qua BFS (Ma tran ke):      ";
    while (!hd.laRong()) {
        int u = hd.layRa();
        cout << TEN_TINH[u];
        
        bool coPhanTuKeTiep = false;
        for (int v = 0; v < SO_DINH; v++) {
            if (maTranKe[u][v] == 1 && !daTham[v]) {
                daTham[v] = true;
                hd.themVao(v);
                coPhanTuKeTiep = true;
            }
        }
        if (!hd.laRong()) cout << " -> ";
    }
    cout << " (Ket thuc)\n";
}

// 6. THUAT TOAN BFS CHO DANH SACH KE
void duyetBFS_DanhSach(int batDau, NutLienKet* danhSachDau[]) {
    bool daTham[SO_DINH] = {false};
    HangDoi hd;
    hd.khoiTao();

    daTham[batDau] = true;
    hd.themVao(batDau);

    cout << "Ket qua BFS (Danh sach kề):    ";
    while (!hd.laRong()) {
        int u = hd.layRa();
        cout << TEN_TINH[u];

        NutLienKet* tam = danhSachDau[u];
        while (tam != nullptr) {
            int v = tam->maSoDinh;
            if (!daTham[v]) {
                daTham[v] = true;
                hd.themVao(v);
            }
            tam = tam->tiepTheo;
        }
        if (!hd.laRong()) cout << " -> ";
    }
    cout << " (Ket thuc)\n";
}

// 7. HAM CHINH
int main() {
    const int tongSoTuyen = 13;
    TuyenDuong dsTuyenDuong[tongSoTuyen] = {
        {0, 1}, {0, 2}, {0, 6}, {0, 8}, {0, 9}, {0, 10}, // HN noi voi 6 tinh
        {2, 3}, {2, 4}, {3, 4},                          // Cac tuyen phia Bac
        {4, 5}, {6, 5},                                  // Ket noi Hai Phong
        {6, 7}, {8, 7}                                   // Ket noi Hung Yen
    };

    // PHAN 1: CAI DAT MA TRAN KE
    int maTran[SO_DINH][SO_DINH] = {0};
    for (int i = 0; i < tongSoTuyen; i++) {
        int u = dsTuyenDuong[i].tinh_U;
        int v = dsTuyenDuong[i].tinh_V;
        maTran[u][v] = 1;
        maTran[v][u] = 1;
    }
    duyetBFS_MaTran(0, maTran); // Tham so thu 2 la ma tran ke

    cout << "--------------------------------------------------\n";

    // PHAN 2: CAI DAT DANH SACH KE
    NutLienKet* danhSachDau[SO_DINH];
    for (int i = 0; i < SO_DINH; i++) danhSachDau[i] = nullptr;
    for (int i = 0; i < tongSoTuyen; i++) {
        int u = dsTuyenDuong[i].tinh_U;
        int v = dsTuyenDuong[i].tinh_V;
        
        // Them vao danh sach cua U
        NutLienKet* moiU = new NutLienKet{v, danhSachDau[u]};
        danhSachDau[u] = moiU;
        
        // Them vao danh sach cua V
        NutLienKet* moiV = new NutLienKet{u, danhSachDau[v]};
        danhSachDau[v] = moiV;
    }
    duyetBFS_DanhSach(0, danhSachDau); // Tham so thu 2 la mang danh sach dau

    return 0;
}