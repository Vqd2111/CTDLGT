#include <iostream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

const int SO_TINH = 11;
const int VO_CUC = 999999;

string tenCacTinh[SO_TINH] = {
    "Ha Noi", "Thai Nguyen", "Bac Ninh", "Bac Giang", "Uong Bi",
    "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay"
};

struct MangLuoiGiaoThong {
    int soLuongDinh;
    int maTranKhoangCach[SO_TINH][SO_TINH];
};

void khoiTaoMangLuoi(MangLuoiGiaoThong &ml, int soDinh) {
    ml.soLuongDinh = soDinh;
    for(int i = 0; i < soDinh; i++)
        for(int j = 0; j < soDinh; j++)
            ml.maTranKhoangCach[i][j] = 0;
}

// [MỚI] Ham them tuyen duong 2 chieu
void themTuyenDuong(MangLuoiGiaoThong &ml, int u, int v, int khoangCach) {
    ml.maTranKhoangCach[u][v] = khoangCach;
    ml.maTranKhoangCach[v][u] = khoangCach;
}

// [MỚI] Ham in ma tran ra man hinh
void inMaTran(int maTran[SO_TINH][SO_TINH], int kichThuoc) {
    cout << setw(15) << "";
    for(int i = 0; i < kichThuoc; i++) cout << setw(13) << tenCacTinh[i];
    cout << "\n";
    for(int i = 0; i < kichThuoc; i++) {
        cout << setw(15) << tenCacTinh[i];
        for(int j = 0; j < kichThuoc; j++) {
            cout << setw(13) << maTran[i][j];
        }
        cout << "\n";
    }
}

int main() {
    MangLuoiGiaoThong banDo;
    khoiTaoMangLuoi(banDo, SO_TINH);

    // [MỚI] Nap du lieu 13 tuyen duong (trong so tam de la 1)
    int dsTuyenDuong[][3] = {
        {0,6,1}, {6,7,1}, {7,8,1}, {0,8,1}, {0,9,1}, {0,10,1},
        {0,1,1}, {0,2,1}, {2,3,1}, {3,4,1}, {2,4,1}, {4,5,1}, {6,5,1}
    };
    int soTuyen = sizeof(dsTuyenDuong) / sizeof(dsTuyenDuong[0]);
    for(int i = 0; i < soTuyen; i++) {
        themTuyenDuong(banDo, dsTuyenDuong[i][0], dsTuyenDuong[i][1], dsTuyenDuong[i][2]);
    }

    cout << "=== MA TRAN KHOANG CACH BAN DAU ===\n\n";
    inMaTran(banDo.maTranKhoangCach, SO_TINH);

    return 0;
}