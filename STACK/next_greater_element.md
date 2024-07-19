# FIND THE NEXT GREATER ELEMENT

## Problem statement

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Example:

```
Input: arr[] = [4, 5, 2, 25]
Output: 
4 --> 5
5 --> 25
2 --> 25
25 --> -1
```
Explain: except 25 every element has an element greater then them present on the right side

```
Input: arr[] = [ 13 , 7, 6 , 12 ]
Output:  
13      -->    -1
7       -->     12
6       -->     12
12      -->     -1
```

Explain: 13 and 12 don't have any element greater then them present on the right side

