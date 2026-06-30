#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int SO_TINH = 11;
const int INF = 1e9;
const string DSTinh[SO_TINH] = {"HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};

struct Matran {
    int n;
    int matrix[SO_TINH][SO_TINH];
};

// Khoi tao ma tran ke rong
void KhoiTaoMaTran(Matran &g, int soDinh) {
    g.n = soDinh;
    for (int i = 0; i < soDinh; i++) {
        for (int j = 0; j < soDinh; j++) {
            g.matrix[i][j] = 0;
        }
    }
}

// Them tuyen duong hai chieu vao do thi
void ThemDuong(Matran &g, int u, int v, int ts) {
    g.matrix[u][v] = ts;
    g.matrix[v][u] = ts;
}

// Hien thi ma tran ra man hinh
void InMaTran(int P[SO_TINH][SO_TINH], int n) {
    cout << setw(6) << " ";
    for (int j = 0; j < n; j++) cout << setw(5) << DSTinh[j];
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << setw(6) << DSTinh[i];
        for (int j = 0; j < n; j++) {
            if (i != j && P[i][j] == 0) cout << setw(5) << "-";
            else cout << setw(5) << P[i][j];
        }
        cout << "\n";
    }
}

int main() {
    Matran g;
    KhoiTaoMaTran(g, SO_TINH);

    // Du lieu trong so tuong ung voi chi so duong D1-D13 tren ban do
    int dsTuyenDuong[][3] = {
        {0, 6, 1}, {6, 7, 2}, {8, 7, 3}, {0, 8, 4}, {0, 9, 5},
        {0, 10, 6}, {0, 1, 7}, {0, 2, 8}, {2, 3, 9}, {3, 4, 10},
        {2, 4, 11}, {4, 5, 12}, {6, 5, 13}
    };
    
    int soTuyen = sizeof(dsTuyenDuong) / sizeof(dsTuyenDuong[0]);
    for (int i = 0; i < soTuyen; i++) {
        ThemDuong(g, dsTuyenDuong[i][0], dsTuyenDuong[i][1], dsTuyenDuong[i][2]);
    }

    cout << "=== MA TRAN TRONG SO BAN DAU ===\n\n";
    InMaTran(g.matrix, SO_TINH);

    return 0;
}