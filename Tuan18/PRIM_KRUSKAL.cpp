#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

const int Sotinh_max = 11;
const int INF = 1e9;
const string DSTinh[Sotinh_max] = { "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST" };

struct Matran {
    int Sotinhxet;
    int matrix[Sotinh_max][Sotinh_max];
};

// Khoi tao ma tran trong
void Khoitaomatran(Matran &g, int n) {
    g.Sotinhxet = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g.matrix[i][j] = 0;
}

// Them tuyen duong vo huong
void ThemDuongMaTran(Matran &g, int u, int v, int matuyen) {
    g.matrix[u][v] = matuyen;
    g.matrix[v][u] = matuyen;
}

// In ma tran de kiem tra
void Inmatran(int P[Sotinh_max][Sotinh_max], int n) {
    cout << setw(6) << " ";
    for (int j = 0; j < n; j++) cout << setw(5) << DSTinh[j];
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << setw(6) << DSTinh[i];
        for (int j = 0; j < n; j++) {
            if (P[i][j] == 0) cout << setw(5) << "-";
            else cout << setw(5) << P[i][j];
        }
        cout << "\n";
    }
}