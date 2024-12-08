# **BẢNG CHIA (SPARSE TABLE)**

Sparse table là cấu trúc dữ liệu thường được sử dụng để trả lời các câu hỏi truy vấn khoảng:

- Sparse table có thể trả lời đa phần các truy vấn trong $O(\log{n})$.

- Nếu như hàm thỏa mãn tính cách **idempotence** (một giá trị có thể xuất hiện nhiều lần nhưng không làm thay đổi kết quả phép toán, như **LCM, GCD, MIN, MAX, AND, OR, ...**) thì các truy vấn có thể chỉ mất $O(1)$ thời gian để trả lời.

- Điểm trừ lớn nhất là Segment Tree có thể xử lý được hoạt động **sửa đổi xen kẽ** với các truy vấn, còn Sparse Table thì không.

