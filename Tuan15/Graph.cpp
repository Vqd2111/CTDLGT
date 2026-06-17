#include <iostream>
#include <string>

using namespace std;

const int SO_DINH = 11;
const char* TEN_TINH[SO_DINH] = {"HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};

struct HangDoi {
    int duLieu[SO_DINH + 5];
    int dau, cuoi;
    void khoiTao() { dau = cuoi = 0; }
    bool laRong() { return dau == cuoi; }
    void themVao(int val) { duLieu[cuoi++] = val; }
    int layRa() { return duLieu[dau++]; }
};

struct NutDanhSach {
    int maSoTinh;
    NutDanhSach* tiepTheo;
};

struct TuyenDuong { int tinh_u, tinh_v; };

void duyetRongMaTran(int batDau, int maTranKe[SO_DINH][SO_DINH]) {
    bool daTham[SO_DINH] = {false};
    HangDoi hd; hd.khoiTao();
    daTham[batDau] = true; hd.themVao(batDau);
    cout << "Ket qua BFS (Ma tran ke):      ";
    while (!hd.laRong()) {
        int u = hd.layRa();
        cout << TEN_TINH[u] << " -> ";
        for (int v = 0; v < SO_DINH; v++) {
            if (maTranKe[u][v] == 1 && !daTham[v]) {
                daTham[v] = true;
                hd.themVao(v);
            }
        }
    }
    cout << "KET THUC\n";
}

void duyetRongDanhSach(int batDau, NutDanhSach* dsDau[]) {
    bool daTham[SO_DINH] = {false};
    HangDoi hd; hd.khoiTao();
    daTham[batDau] = true; hd.themVao(batDau);
    cout << "Ket qua BFS (Danh sach kề):    ";
    while (!hd.laRong()) {
        int u = hd.layRa();
        cout << TEN_TINH[u] << " -> ";
        NutDanhSach* hienTai = dsDau[u];
        while (hienTai != nullptr) {
            int v = hienTai->maSoTinh;
            if (!daTham[v]) {
                daTham[v] = true;
                hd.themVao(v);
            }
            hienTai = hienTai->tiepTheo;
        }
    }
    cout << "KET THUC\n";
}

int main() {
    const int tongTuyen = 13;
    TuyenDuong danhSachTuyen[tongTuyen] = {
        {0, 1}, {0, 2}, {0, 6}, {0, 8}, {0, 9}, {0, 10},
        {2, 3}, {2, 4}, {3, 4}, {4, 5}, {6, 5}, {6, 7}, {8, 7}
    };

    // 1. Ma tran ke
    int maTran[SO_DINH][SO_DINH] = {0};
    for (int i = 0; i < tongTuyen; i++) {
        maTran[danhSachTuyen[i].tinh_u][danhSachTuyen[i].tinh_v] = 1;
        maTran[danhSachTuyen[i].tinh_v][danhSachTuyen[i].tinh_u] = 1;
    }
    duyetRongMaTran(0);

    // 2. Danh sach ke
    NutDanhSach* dsDau[SO_DINH];
    for (int i = 0; i < SO_DINH; i++) dsDau[i] = nullptr;
    for (int i = 0; i < tongTuyen; i++) {
        NutDanhSach* nutMoiU = new NutDanhSach{danhSachTuyen[i].tinh_v, dsDau[danhSachTuyen[i].tinh_u]};
        dsDau[danhSachTuyen[i].tinh_u] = nutMoiU;
        NutDanhSach* nutMoiV = new NutDanhSach{danhSachTuyen[i].tinh_u, dsDau[danhSachTuyen[i].tinh_v]};
        dsDau[danhSachTuyen[i].tinh_v] = nutMoiV;
    }
    duyetRongDanhSach(0);

    return 0;
}