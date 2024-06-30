# **MERGE SORT**

## Problem statement

Given two sorted array, print the combined array after sorted.

### **Example 1:**
```
>>> a[] = [10, 15, 20]
>>> b[] = [5, 6, 6, 15]
>>> Output:5 6 6 10 15 15 20
```

### **Example 2**
```
>>> a[] = [1, 1, 2]
>>> b[] = [3]
>>> Output: 1 1 2 3
```

## ***Naive solution***

### **Idea:**

> We define array `c` to have the size of `m + n`. Then we loop through the first array to insert all of them into array `c`. Then, add all the elements of array b to the back of array c. Then use `sort()` function to sort array `c`.

```cpp
void merge(int a[], int b[], int m, int n){
    int c[m + n];
    for (int i = 0; i < m; i++)
        c[i] = a[i];
    for (int j = 0; j < n; j++)
        c[m + j] = b[j];
    sort(c, c + m + n);
    for (int i = 0; i < m + n; i++) 
        cout << c[i] << " ";
}
```
> * Time complexity: $O((m + n)\times{\log{(m + n)}})$
> * Auxiliary space: $O((m + n))$

## ***Efficient solution***

### **Idea:**
- Traverse two arrays simultaneously
- Compare `a[i]` with `b[j]`
    * If `a[i] <= b[j]: print(a[i]); i++`
    * If `a[i] > b[j]: print(b[j]); j++;`

### **Implementation**
```cpp
void merge(int a[], int b[], int m, int n){
    
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<b[j])
            cout<<a[i++]<<" ";
        else
            cout<<b[j++]<<" ";
    }
    while(i<m)
        cout<<a[i++]<<" ";
    while(j<n)
        cout<<b[j++]<<" ";    
}
```

# **MERGE FUNCTION OF MERGE SORT**

## ***Problem statement***

Given an array `a[]` and three indices `low, mid, high`. We know that array `a[]` is not sorted wholy from `low` to `high` but are sorted partly, from `low` to `mid` and from `mid` to `high`. 

Your job is to sort array `a[]` wholy from `low` to `high`.

Condition: `low <= mid < high`

Example:
```
>>> a[] = [10, 15, 20, 11, 30]
>>> low, mid, high = 0, 2, 4
>>> Output: 10, 11, 15, 20, 30
```

## ***Solution***

### **Idea**

- Split the aray into two halves:
    - `left[]` array from `low` to `mid`
    - `right[]` array from `mid` to `high`
- Then, do the same as merge two sorted arrays

### **Implementation:**

```cpp
void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}
```

# **MERGE SORT ALGORITHM**

## ***Problem statement***

Use merge sort technique to sort an array

## **Implementation**

### CPP
```cpp
void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}

void mergeSort(int arr[],int l,int r){
    if(r>l){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
```

### Python
```py
def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
 
    # create temp arrays
    L = [0] * (n1)
    R = [0] * (n2)
 
    # Copy data to temp arrays L[] and R[]
    for i in range(0, n1):
        L[i] = arr[l + i]
 
    for j in range(0, n2):
        R[j] = arr[m + 1 + j]
 
    # Merge the temp arrays back into arr[l..r]
    i = 0     # Initial index of first subarray
    j = 0     # Initial index of second subarray
    k = l     # Initial index of merged subarray
 
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
 
    # Copy the remaining elements of L[], if there
    # are any
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
 
    # Copy the remaining elements of R[], if there
    # are any
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1
 
# l is for left index and r is right index of the
# sub-array of arr to be sorted
 
 
def mergeSort(arr, l, r):
    if l < r:
 
        # Same as (l+r)//2, but avoids overflow for
        # large l and h
        m = l+(r-l)//2
 
        # Sort first and second halves
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)
```