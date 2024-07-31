# **BITWISE OEPRATORS**

These operators are used to perform bit-level operations on the operands. The operators are first converted to bit-level and then the calculation is performed on the operands. The mathematical operations such as addition, subtraction, multiplication, etc. can be performed at the bit-level for faster processing. 

## ***AND (&)***

- Principle: produce bit 1 if two numbers have the same bit of 1 (any one of them having 0 --> automically 0)

- Copies a bit to the evaluated result if it exists in both operands. 

- Example: a = 3, b = 6

    - Binary representation: a = 00000011, b = 00000110

    - a & b = 00000010 --> (a & b) = 2

## ***OR (|)***

- Principle: produce bit 1 if any of two numbers have bit of 1 (both of them having 0 --> automically 0)

- Copies a bit to the evaluated result if it exists in any of the operand	

- Example: a = 3, b = 6

    - Binary representation: a = 00000011, b = 00000110

    - a | b = 00000111 --> (a | b) = 7

## ***XOR (^)***

- Principle: produce bit if two numbers have different bits (same bit --> 0)

- Copies the bit to the evaluated result if it is present in either of the operands but not both	

- Example: a = 3, b = 6

    - Binary representation: a = 00000011, b = 00000110

    - a ^ b = 00000101 --> (a ^ b) = 5

## ***Left Shift Operator (<<)***

- Shifts the value to left by the number of bits specified by the right operand.

- For example: x = 3, x << 1 --> 6

- Giải thích: ta dịch biểu thị thập phân của `x` sang một bit thập phân. Ban đầu, biểu diễn thập phân của `x` là 000....**011**. Sau khi thực hiện phép toán dịch trái (<<), biểu diễn thập phân của `x` trở thành 000...**0110**. 

- Nếu như x << 2 --> 000...011 thành 000...**01100**.

- Nói cách khác, ta có thể biểu diễn phép dịch bit sang trái như sau:

$$
x << y = x \times 2^y
$$

## ***Right Shift Operator***

- Shifts the value to right by the number of bits specified by the right operand. The last bit will be ignored.

- For example: x = 33, x << 1 --> 16

- Nói cách khác, ta có thể biểu diễn phép dịch bit sang phải như sau:

$$
x >> y = \left⌊\frac{x}{2^y}\right⌋
$$

## ***NOT (~)***

- Changes binary digits 1 to 0 and 0 to 1	

- Example: ~5 = -6

- Nếu sử dụng `unsigned int` thì phép NOT chỉ trả về số dương. Ví dụ, 0 --> 2^31 - 1