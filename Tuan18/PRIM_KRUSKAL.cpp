#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>

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
        for (int j = 0; j < soDinh; j++) g.matrix[i][j] = 0;
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

// Thuat toan Dijkstra tim chi phi di lai thap nhat tu mot dinh
void ThuatToanDijkstra(Matran g, int start) {
    int n = g.n;
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (g.matrix[u][v] > 0) {
                if (dist[u] + g.matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + g.matrix[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << "\n=== DIJKSTRA: DUONG DI NGAN NHAT TU " << DSTinh[start] << " ===\n";
    for (int i = 0; i < n; i++) {
        if (i != start && dist[i] != INF)
            cout << "Den " << DSTinh[i] << ": Trong so = " << dist[i] << "\n";
    }
}

int main() {
    Matran g;
    KhoiTaoMaTran(g, SO_TINH);

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

    ThuatToanDijkstra(g, 0);

    return 0;
}