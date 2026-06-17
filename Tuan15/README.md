# BÀI TẬP TUẦN 14 - CẤU TRÚC DỮ LIỆU ĐỒ THỊ VÀ GIẢI THUẬT BFS

**Môn học:** Cấu trúc dữ liệu và Giải thuật  
 

## 1. Giới thiệu bài toán
Chương trình mô phỏng mạng lưới giao thông gồm **11 nút (tỉnh/thành phố)** kết nối với nhau qua **13 tuyến đường (cạnh)**. Mục tiêu của bài tập là biểu diễn đồ thị bằng hai phương pháp lưu trữ khác nhau và thực hiện duyệt đồ thị theo chiều rộng (BFS).

### Bảng quy ước định danh hệ thống:
| STT | Ký hiệu | Chỉ số mảng | Tên tỉnh / Thành phố |
| :-- | :--- | :--- | :--- |
| 1 | HN | 0 | Hà Nội (Điểm xuất phát) |
| 2 | TN | 1 | Thái Nguyên |
| 3 | BN | 2 | Bắc Ninh |
| 4 | BG | 3 | Bắc Giang |
| 5 | UB | 4 | Uông Bí |
| 6 | HP | 5 | Hải Phòng |
| 7 | HD | 6 | Hải Dương |
| 8 | HY | 7 | Hưng Yên |
| 9 | PL | 8 | Phủ Lý |
| 10 | HB | 9 | Hòa Bình |
| 11 | ST | 10 | Sơn Tây |

---

## 2. Cấu trúc dữ liệu cài đặt


### 2.1. Hàng đợi tự định nghĩa (`struct HangDoi`)
Sử dụng cấu trúc Hàng đợi tĩnh để điều khiển thuật toán BFS theo nguyên lý **FIFO** (First In - First Out):
- `mangLuuTru[]`: Lưu các đỉnh đang chờ duyệt.
- `dau`, `cuoi`: Quản lý vị trí nạp và rút phần tử.

### 2.2. Phương pháp 1: Ma trận kề (`int maTranKe[11][11]`)
- Lưu trữ đồ thị bằng mảng hai chiều.
- Giá trị `1` tại vị trí `[u][v]` biểu thị có đường đi giữa tỉnh `u` và tỉnh `v`.
- Ưu điểm: Kiểm tra kết nối giữa 2 tỉnh cực nhanh ($O(1)$).

### 2.3. Phương pháp 2: Danh sách kề (`struct NutLienKet`)
- Sử dụng mảng các con trỏ quản lý danh sách liên kết đơn của từng đỉnh.
- Ưu điểm: Tiết kiệm bộ nhớ khi đồ thị có ít cạnh (đồ thị thưa).


---

## 3. Hướng dẫn chạy chương trình
1. Sử dụng trình biên dịch C++ (g++) để biên dịch file `Graph.cpp`.
2. Chạy file thực thi để xem kết quả duyệt BFS từ Hà Nội.

### Kết quả kỳ vọng:
> Ket qua BFS (Ma tran ke):      Ha Noi -> Thai Nguyen -> Bac Ninh -> Hai Duong -> Phu Ly -> Hoa Binh -> Son Tay -> Bac Giang -> Uong Bi -> Hai Phong -> Hung Yen -> (Ket thuc)
> Ket qua BFS (Danh sach kề):    Ha Noi -> Son Tay -> Hoa Binh -> Phu Ly -> Hai Duong -> Bac Ninh -> Thai Nguyen -> Hung Yen -> Hai Phong -> Uong Bi -> Bac Giang -> (Ket thuc)

### xem két quả trong file kq_tuan15.png
---

## 4. Danh sách tuyến đường (13 cạnh)
- HN nối với: TN, BN, HD, PL, HB, ST (6 đường)
- BN - BG, BN - UB, BG - UB (3 đường)
- UB - HP, HD - HP (2 đường)
- HD - HY, PL - HY (2 đường)