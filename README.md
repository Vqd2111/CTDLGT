# 🗂️ Quản lý File bằng Danh sách Liên kết Đơn (SLL)

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structure](https://img.shields.io/badge/Data_Structure-Linked_List-FFb902?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

Dự án bài tập môn **Cấu trúc dữ liệu và Giải thuật**. Ứng dụng cấu trúc dữ liệu danh sách liên kết đơn để mô phỏng hệ thống quản lý tệp tin và logic sao lưu dữ liệu thông minh.

---

---

## ✨ Tính năng cốt lõi (Features)

- 📥 **Chèn có thứ tự (Sorted Insert):** Tự động sắp xếp file ngay khi thêm vào dựa trên trật tự thời gian tăng dần.
- 🧮 **Tính toán dung lượng:** Duyệt danh sách để tính tổng kích thước các file hiện có trong bộ nhớ.
- 🗑️ **Thuật toán Backup:** Tự động dò tìm và giải phóng (`delete`) các file có dung lượng nhỏ nhất để tối ưu hóa không gian lưu trữ cho USB 32GB.

---

## 🧠 Phân tích Thuật toán

### 1. Sơ đồ logic xóa File nhỏ nhất (Delete Min)
Để xóa file nhỏ nhất, thuật toán cần ghi nhớ Node mục tiêu và Node đứng trước nó để ngắt liên kết mà không làm gãy danh sách.



```mermaid
graph LR
    pHead((pHead)) --> Node1
    
    Node1["Node 1 (prevMin)<br>Size: 50MB"] 
    Node2["Node 2 (minNode)<br>Size: 10MB"] 
    Node3["Node 3<br>Size: 30MB"] 
    
    Node1 -->|pNext cũ| Node2
    Node2 -->|pNext| Node3
    Node3 --> NullNode(("NULL"))
    
    Node1 -.->|prevMin->pNext = minNode->pNext| Node3
    
    style Node2 fill:#ffcccc,stroke:#ff0000,stroke-width:2px,stroke-dasharray: 5 5
    style pHead fill:#87CEEB,stroke:#333,stroke-width:2px
