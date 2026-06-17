#include <iostream>
#include <string>

using namespace std;

const int SO_DINH = 11;
const char* TEN_TINH[SO_DINH] = {"HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};

struct DoThiMaTran {
    int maTranKe[SO_DINH][SO_DINH];

    void khoiTao() {
        for (int i = 0; i < SO_DINH; i++)
            for (int j = 0; j < SO_DINH; j++)
                maTranKe[i][j] = 0;
    }

    void themCanh(int u, int v) {
        maTranKe[u][v] = 1;
        maTranKe[v][u] = 1; // Do thi vo huong
    }
};

int main() { return 0; }