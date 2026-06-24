#include <iostream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

const int SO_TINH = 11;
const int VO_CUC = 999999;

typedef pair<int, int> Dinh_ChiPhi;

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

void themTuyenDuong(MangLuoiGiaoThong &ml, int u, int v, int khoangCach) {
    ml.maTranKhoangCach[u][v] = khoangCach;
    ml.maTranKhoangCach[v][u] = khoangCach;
}

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

void thuatToanWarshall(MangLuoiGiaoThong ml, int maTranLienThong[SO_TINH][SO_TINH]) {
    int n = ml.soLuongDinh;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j || ml.maTranKhoangCach[i][j] != 0) maTranLienThong[i][j] = 1;
            else maTranLienThong[i][j] = 0;
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(maTranLienThong[i][j] == 0)
                    maTranLienThong[i][j] = maTranLienThong[i][k] && maTranLienThong[k][j];
            }
        }
    }
}

void thuatToanDijkstra(MangLuoiGiaoThong ml, int startNode, int khoangCachNganNhat[], int vetLui[]) {
    int n = ml.soLuongDinh;
    priority_queue<Dinh_ChiPhi, vector<Dinh_ChiPhi>, greater<Dinh_ChiPhi>> pq;

    for(int i = 0; i < n; i++) {
        khoangCachNganNhat[i] = VO_CUC;
        vetLui[i] = -1;
    }

    khoangCachNganNhat[startNode] = 0;
    pq.push({0, startNode}); 

    while(!pq.empty()) {
        int u = pq.top().second;
        int chiPhi_u = pq.top().first;
        pq.pop();

        if(chiPhi_u > khoangCachNganNhat[u]) continue;

        for(int v = 0; v < n; v++) {
            if(ml.maTranKhoangCach[u][v] != 0) { 
                int chiPhiMoi = khoangCachNganNhat[u] + ml.maTranKhoangCach[u][v];
                if(chiPhiMoi < khoangCachNganNhat[v]) {
                    khoangCachNganNhat[v] = chiPhiMoi;
                    vetLui[v] = u;
                    pq.push({chiPhiMoi, v});
                }
            }
        }
    }
}

// [MỚI] Ham de quy in ra lo trinh
void truyVetDuongDi(int dichDen, int vetLui[]) {
    if(dichDen == -1) return;
    
    truyVetDuongDi(vetLui[dichDen], vetLui);
    
    if(vetLui[dichDen] != -1) cout << " -> ";
    cout << tenCacTinh[dichDen];
}

int main() {
    MangLuoiGiaoThong banDo;
    khoiTaoMangLuoi(banDo, SO_TINH);

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

    int mtWarshall[SO_TINH][SO_TINH];
    thuatToanWarshall(banDo, mtWarshall);

    cout << "\n\n=== MA TRAN WARSHALL (KIEM TRA LIEN THONG) ===\n\n";
    inMaTran(mtWarshall, SO_TINH);

    if(mtWarshall[0][4] == 1) cout << "\n=> Co duong di tu Ha Noi den Uong Bi\n";
    else cout << "\n=> Khong co duong di tu Ha Noi den Uong Bi\n";

    // [MỚI] Goi Dijkstra va truy vet
    int chiPhi[SO_TINH];
    int vet[SO_TINH];
    thuatToanDijkstra(banDo, 0, chiPhi, vet);

    cout << "\n=== DIJKSTRA - DUONG DI NGAN NHAT ===\n";
    cout << "Tong so chang tu Ha Noi (0) den Uong Bi (4): " << chiPhi[4] << "\n";
    cout << "Chi tiet lo trinh: ";
    truyVetDuongDi(4, vet);
    cout << "\n";

    return 0;
}