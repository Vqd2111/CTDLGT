void duyetRongDanhSach(int batDau, NutDanhSach* dsDau[], const char* ten[]) {
    bool daTham[SO_DINH] = {false};
    HangDoi hd; hd.khoiTao();

    daTham[batDau] = true;
    hd.themVao(batDau);

    cout << "BFS (Danh sach kề):    ";
    while (!hd.laRong()) {
        int u = hd.layRa();
        cout << ten[u] << " -> ";
        NutDanhSach* hienTai = dsDau[u];
        while (hienTai != nullptr) {
            if (!daTham[hienTai->maSoTinh]) {
                daTham[hienTai->maSoTinh] = true;
                hd.themVao(hienTai->maSoTinh);
            }
            hienTai = hienTai->tiepTheo;
        }
    }
    cout << "KET THUC\n";
}