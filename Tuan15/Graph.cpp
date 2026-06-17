#include <iostream>
#include <string>

using namespace std;

const int SO_DINH = 11;

// Cau truc Hang doi tu dinh nghia (Manual Queue)
struct HangDoi {
    int duLieu[SO_DINH + 5];
    int dau, cuoi;

    void khoiTao() {
        dau = 0;
        cuoi = 0;
    }

    bool laRong() {
        return dau == cuoi;
    }

    void themVao(int giaTri) {
        duLieu[cuoi++] = giaTri;
    }

    int layRa() {
        return duLieu[dau++];
    }
};

int main() {
    cout << "--- KHOI TAO HANG DOI THANH CONG ---\n";
    return 0;
}