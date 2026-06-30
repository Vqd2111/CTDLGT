# Tối ưu hóa Đồ thị Giao thông (Tuần 15)

Sinh viên thực hiện: Vũ Quang Duy (MSSV: 20223936)  

## 1. Mục tiêu
Chương trình ứng dụng cấu trúc dữ liệu đồ thị để mô phỏng mạng lưới giao thông 11 tỉnh thành, tiến hành tìm đường đi ngắn nhất và xây dựng mạng lưới kết nối tối ưu (Cây khung nhỏ nhất).

## 2. Giải thuật áp dụng
* **Dijkstra:** Tìm quãng đường ngắn nhất từ đỉnh nguồn (Hà Nội) đến toàn bộ các tỉnh thành còn lại sử dụng Hàng đợi ưu tiên (`priority_queue`).
* **Prim:** Xây dựng Cây khung nhỏ nhất (MST) và xuất kết quả dưới dạng Ma trận đỉnh kề.
* **Kruskal:** Thu thập và sắp xếp cạnh, sử dụng cấu trúc tập hợp rời rạc (Disjoint-Set) để triệt tiêu chu trình, xuất kết quả dưới dạng Ma trận đỉnh kề.

## 3. Dữ liệu Hệ thống
* **Danh sách đỉnh (11):** HN, TN, BN, BG, UB, HP, HD, HY, PL, HB, ST.
* **Danh sách cạnh (13):** Trọng số của các tuyến đường được ánh xạ trực tiếp từ mã tuyến trên sơ đồ (D1 = 1, D10 = 10, D13 = 13...).
* Tổng trọng số cây khung tối ưu (Prim/Kruskal): **63**.

