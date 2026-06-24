# Phân tích Thuật toán Đồ thị Giao thông - Tuần 16
*Thực hiện: Duy*

## 1. Cấu trúc chương trình
- Sử dụng danh sách tĩnh lưu tên 11 tỉnh thành để ánh xạ với các chỉ số mảng (0-10).
- Cấu trúc `MangLuoiGiaoThong` bao gồm kích thước đồ thị và ma trận khoảng cách `11x11`.

## 2. Giải thuật áp dụng
**A. Thuật toán Warshall:**
- Mục tiêu: Tìm Bao đóng chuyển tiếp (Transitive Closure).
- Ứng dụng: Trả lời câu hỏi logic "Liệu có thể đi từ tỉnh A đến tỉnh B hay không?".
- Thay vì chỉ dựa vào cạnh trực tiếp, thuật toán xem xét mọi đỉnh trung gian `k` để tìm đường gián tiếp.

**B. Thuật toán Dijkstra:**
- Mục tiêu: Tìm đường đi ngắn nhất / tốn ít chi phí nhất.
- Ứng dụng: Chỉ ra lộ trình chính xác cần di chuyển qua các tỉnh nào.
- Kỹ thuật: Cài đặt nâng cao sử dụng `priority_queue` (Hàng đợi ưu tiên) với cặp giá trị `pair<int, int>` để luôn duyệt đỉnh có chi phí tiềm năng thấp nhất.
