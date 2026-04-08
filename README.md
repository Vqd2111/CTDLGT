# 🗂️ Quản lý File bằng Danh sách Liên kết Đơn (SLL)

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structure](https://img.shields.io/badge/Data_Structure-Linked_List-FFb902?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

Dự án bài tập môn Cấu trúc dữ liệu và Giải thuật (Tuần 6). Ứng dụng cấu trúc **Danh sách liên kết đơn (Single Linked List)** để mô phỏng hệ thống quản lý tệp tin và logic sao lưu dữ liệu tự động.
---

## ✨ Tính năng cốt lõi (Features)
- 📥 **Chèn có thứ tự (Sorted Insert):** Thêm file mới và tự động sắp xếp theo thứ tự thời gian tăng dần.
- 🧮 **Tính toán dung lượng:** Duyệt danh sách để tính tổng kích thước các file hiện có.
- 🗑️ **Thuật toán Backup thông minh:** Tự động dò tìm và gỡ bỏ (Delete Min) các file có dung lượng nhỏ nhất cho đến khi tổng dữ liệu vừa vặn với ổ USB 32GB (32768 MB).

## 🧠 Sơ đồ Thuật toán ngắt liên kết (Delete Min)

```mermaid
graph LR
    pHead((pHead)) --> Node1
    
    Node1["Node 1 (prevMin)<br>Time: 1 | Size: 50MB"] 
    Node2["Node 2 (minNode)<br>Time: 2 | Size: 10MB"] 
    Node3["Node 3<br>Time: 3 | Size: 30MB"] 
    
    Node1 -->|pNext cũ| Node2
    Node2 -->|pNext| Node3
    Node3 --> NullNode(("NULL"))
    
    Node1 -.->|prevMin->pNext = minNode->pNext| Node3
    
    style Node2 fill:#ffcccc,stroke:#ff0000,stroke-width:2px,stroke-dasharray: 5 5
    style pHead fill:#87CEEB,stroke:#333,stroke-width:2px
    style NullNode fill:#d3d3d3,stroke:#333,stroke-width:2px
