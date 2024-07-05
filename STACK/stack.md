# **STACK**

## ***What is stack?***

It is a linear data structure that follows a particular order in which the operations are performed.

## ***Basic operations on stack***

- `push()` to insert an element into the stack
- `pop()` to remove an element from the stack
- `top()` Returns the top element of the stack.
- `isEmpty()` returns true if stack is empt

### *Complexity analysis*

![alt text](image.png)

## ***Applications of stack***

# **BALANCED PARENTHESIS**

## ***Problem statement***

Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

> **Example**

> Input: exp = “[()]{}{[()()]()}” 
>
> Output: Balanced
>
> Explanation: all the brackets are well-formed

> 
> Input: exp = “[(])” 
>
> Output: Not Balanced 
>
> Explanation: 1 and 4 brackets are not balanced because there is a closing ‘]’ before the closing ‘(‘

## ***Check for balanced bracket expression using stack***

The idea is to put all the opening brackets in the stack. Whenever you hit a closing bracket, search if the top of the stack is the opening bracket of the same nature. If this holds then pop the stack and continue the iteration, in the end if the stack is empty, it means all brackets are well-formed . Otherwise, they are not balanced.

Below is the illustration of the above approach.

![alt text](image-1.png)

Follow the steps mentioned below to implement the idea:

- Declare a character stack (say temp).
- Now traverse the string exp. 
    - If the current character is a starting bracket ( ‘(‘ or ‘{‘  or ‘[‘ ) then push it to stack.
    - If the current character is a closing bracket ( ‘)’ or ‘}’ or ‘]’ ) then pop from stack and if the popped character is the matching starting bracket then fine.
    - Else brackets are Not Balanced.
- After complete traversal, if there is some starting bracket left in stack then Not balanced, else Balanced.

## ***Implementation***
### **CPP**
```cpp
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            } else if (c == ')' && st.top() != '(') {
                return false;
            } else if (c == ']' && st.top() != '[') {
                return false;
            } else if (c == '}' && st.top() != '{') {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}
```
### **Python**
```py
def is_balanced(s):
    stack = []
    for c in s:
        if c in ['(', '[', '{']:
            stack.append(c)
        else:
            if not stack:
                return False
            current_char = stack.pop()
            if current_char == '(':
                if c != ')':
                    return False
            if current_char == '[':
                if c != ']':
                    return False
            if current_char == '{':
                if c != '}':
                    return False
    return len(stack) == 0

```