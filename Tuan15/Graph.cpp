// (Cac phan header giu nguyen...)
void duyetRongMaTran(int batDau, int maTranKe[SO_DINH][SO_DINH], const char* ten[]) {
    bool daTham[SO_DINH] = {false};
    HangDoi hd; hd.khoiTao();

    daTham[batDau] = true;
    hd.themVao(batDau);

    cout << "BFS (Ma tran ke):      ";
    while (!hd.laRong()) {
        int u = hd.layRa();
        cout << ten[u] << " -> ";
        for (int v = 0; v < SO_DINH; v++) {
            if (maTranKe[u][v] == 1 && !daTham[v]) {
                daTham[v] = true;
                hd.themVao(v);
            }
        }
    }
    cout << "KET THUC\n";
}