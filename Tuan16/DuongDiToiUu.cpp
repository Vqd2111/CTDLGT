#include <iostream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

const int SO_TINH = 11;
const int VO_CUC = 999999;

// Khai bao ten cac tinh thanh
string tenCacTinh[SO_TINH] = {
    "Ha Noi", "Thai Nguyen", "Bac Ninh", "Bac Giang", "Uong Bi",
    "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay"
};

// Cau truc luu tru do thi
struct MangLuoiGiaoThong {
    int soLuongDinh;
    int maTranKhoangCach[SO_TINH][SO_TINH];
};

// Ham khoi tao ban do ban dau (toan bo la 0)
void khoiTaoMangLuoi(MangLuoiGiaoThong &ml, int soDinh) {
    ml.soLuongDinh = soDinh;
    for(int i = 0; i < soDinh; i++) {
        for(int j = 0; j < soDinh; j++) {
            ml.maTranKhoangCach[i][j] = 0;
        }
    }
}

int main() {
    MangLuoiGiaoThong banDo;
    khoiTaoMangLuoi(banDo, SO_TINH);
    cout << "--- KHOI TAO HE THONG GIAO THONG THANH CONG ---\n";
    return 0;
}