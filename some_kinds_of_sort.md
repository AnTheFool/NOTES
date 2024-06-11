# **DIVE IN TO SPECIFIC TYPES OF SORTING**

## ***INSERTION SORT***

Insertion Sort is an In-Place sorting algorithm. This algorithm works in a similar way of sorting a deck of playing cards. 

The idea is to start iterating from the second element of array till last element and for every element insert at its correct position in the subarray before it.

In the below image you can see, how the array [4, 3, 2, 10, 12, 1, 5, 6] is being sorted in increasing order following the insertion sort algorithm.

![Sorting](https://media.geeksforgeeks.org/wp-content/uploads/insertionsort.png)

### *HOW THE ALGORITHM WORKS*

* Step 1: If the current element is 1st element of array, it is already sorted.

* Step 2: Pick next element

* Step 3: Compare the current element with all elements in the sorted sub-array before it.

* Step 4: Shift all of the elements in the sub-array before the current element which are greater than the current element by one place and insert the current element at the new empty space.

* Step 5: Repeat step 2-3 until the entire array is sorted.

### *IMPLEMETATION*
```cpp
void insertionSort(int arr[], int n) 
{ 
  
   for (int i = 1; i < n; i++) 
   { 
       int key = arr[i]; 
       int j = i-1; 
     
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 
```

Time complexity: $O(n^2)$

## ***BUBBLE SORT***

Bubble Sort is also an in-place sorting algorithm. This is the simplest sorting algorithm and it works on the principle that:

> In one iteration if we swap all adjacent elements of an array such that after swap the first element is less than the second element then at the end of the iteration, the first element of the array will be the minimum element.

Bubble-Sort algorithm simply repeats the above steps N-1 times, where N is the size of the array.

### *IMPLEMENTATION*
```cpp
void bubbleSort(int arr[], int n) 
{ 
   for (int i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (int j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
```

Time complexity: $O(n^2)$

## **SELECTION SORT**

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1. The subarray which is already sorted.
2. Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 

Following example explains the above steps:
```
// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64
```

### *IMPLEMENTATION*

```cpp
void selectionSort(int arr[], int n)
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
```