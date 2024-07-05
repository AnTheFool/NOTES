# **NAIVE PARTITION**

## **Problem statement**

Given an unsorted array `arr`, and given an index of element inside the array `p`. Requirement: it should partition the array around element having index `p`. If there are elements equal to the element of index `p`, it should come before the element of index `p`

For example:

```
>>> arr[] = [3, 8, 6, 12, 10, 7]
>>> p = 5
>>> Output: 3 6 7 8 12 10
or
>>> Output: 6 3 7 12 8 10
...
```
## **Idea**

- First, create a `temp[]` array that hold `h - l + 1` number of values. 

- Then, traverse firstly through array `arr[]` to check whether the elements are smaller or equal to `arr[p]` or not. If yes, insert that element into `temp[]`

- Do the second traversal the same but with `arr[i] > arr[p]`

- The third loop will copy back the elements in `temp[]` into `arr[]`

## **Implementation**
```cpp
void partition(int arr[], int l, int h, int p)
{
    int temp[h-l+1],index=0;
    for(int i=l;i<=h;i++)
        if(arr[i]<=arr[p] && i != p)
            {
                temp[index]=arr[i];index++;
            }
    temp[index++] = arr[p];
    for(int i=l;i<=h;i++)
        if(arr[i]>arr[p])
            {
                temp[index]=arr[i];index++;
            }
    for(int i=l;i<=h;i++)
        arr[i]=temp[i-l];
}
```

### Time complexity: $O(n)$; memory complexity: $O(n)$

# **LOMUTO PARTITION**

## **How does it work?**

- This algorithm assumes that the last element shall be the pivot.

- Take an example like this: 

    - Suppose we have array `arr[] = [10, 80, 30, 90, 40, 50, 70]`. Pivot here equals `70`.

    - Declare `i = l - 1`.
    
    - Run the loop with `j` from `l` to `h - 1`:

        - If `arr[j] < pivot` then increment of smaller elements, then swap `arr[i]` and `arr[j]`.

        - Otherwise, keep it as natural.
    
    - Stop the loop when `j = h`. 

    - Finally, swap `arr[i]` with `arr[h]` (swap element `i` with the pivot)

## **Implementation**

```cpp
int iPartition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
```

# **HOARE PARTITION**