#include <iostream>
using namespace std;

const int SO_DINH = 11;

struct NutDanhSach {
    int maSoTinh;
    NutDanhSach* tiepTheo;
};

struct DoThiDanhSach {
    NutDanhSach* danhSachDau[SO_DINH];

    void khoiTao() {
        for (int i = 0; i < SO_DINH; i++) danhSachDau[i] = nullptr;
    }

    void themVaoDau(int u, int v) {
        NutDanhSach* nutMoi = new NutDanhSach{v, danhSachDau[u]};
        danhSachDau[u] = nutMoi;
    }

    void themCanh(int u, int v) {
        themVaoDau(u, v);
        themVaoDau(v, u);
    }
};

int main() { return 0; }