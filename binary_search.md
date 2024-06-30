# **BINARY SEARCH**

## WHAT IS BINARY SEARCH

Binary Search is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to $O(\log{n})$.

## IDEA BEHIND
The basic steps to perform Binary Search are:

> - Begin with the mid element of the whole array as a search key.
> - If the value of the search key is equal to the item then return an index of the search key.
> - Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
> - Otherwise, narrow it to the upper half.
> - Repeatedly check from the second point until the value is found or the interval is empty.

## IMPLEMENTATION USING RECURSION
### With C++
```cpp
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}
```
### With Python
```py
# Returns index of x in arr if present, else -1
def binary_search(arr, low, high, x):
 
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1
```

## IMPLEMENTATION USING BUILT-IN FUNCTION (APPLICABLE TO C++ ONLY)

### ```binary_search()```

This function only checks if a particular element is present in a sorted container or not. It accepts the starting iterator, ending iterator and the element to be checked as parameters and returns True if the element is present otherwise False.

**Syntax**

```cpp
binary_search(start_ptr, end_ptr, ele)
```

**Code**

```cpp
// C++ code to demonstrate the working 
// of binary_search() 

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{   
    /*** USING binary_search() ON VECTOR ***/

    // initializing vector of integers 
    vector<int> vec = {10, 15, 20, 25, 30, 35}; 
    
    // using binary_search to check if 15 exists 
    if (binary_search(vec.begin(), vec.end(), 15)) 
        cout << "15 exists in vector"; 
    else
        cout << "15 does not exist"; 
    
    cout << endl; 
    
    /*** USING binary_search() ON ARRAYS ***/
    int arr[] = {10, 15, 20, 25, 30, 35}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // using binary_search to check if 20 exists 
    if (binary_search(arr, arr + n, 20)) 
        cout << "20 exists in Array"; 
    else
        cout << "20 does not exist"; 
    
    return 0;
} 
```

### ```upper_bound()```

The `upper_bound()` function is used to find the upper bound of an element present in a container. That is it finds the location of an element just greater than a given element in a container. This function accepts the start iterator, end iterator and the element to be checked as parameters and returns the iterator pointing to the element just greater than the element passed as the parameter. If there does not exist any such element than the function returns an iterator pointing to the last element.

**Syntax**
```cpp
upper_bound(first_itr, last_itr, ele)
```

**Return Value:** Returns an iterator pointing to the element just greater than ele.

**Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;

// Driver code 
int main() 
{ 
    /*** USING upper_bound() WITH VECTOR ***/
    
    vector<int> v{ 10, 20, 30, 40, 50 }; 

    // Print vector 
    cout << "Vector contains :"; 
    for (int i = 0; i < v.size(); i++) 
        cout << " " << v[i]; 
    cout << "\n"; 

    vector<int>::iterator upper1, upper2; 

    // std :: upper_bound 
    upper1 = upper_bound(v.begin(), v.end(), 35); 
    upper2 = upper_bound(v.begin(), v.end(), 45); 

    cout << "\nUpper_bound for element 35 is at position : "
            << (upper1 - v.begin()); 
    cout << "\nUpper_bound for element 45 is at position : "
            << (upper2 - v.begin())<<"\n\n"; 

    
    /*** USING upper_bound() WITH ARRAY ***/
    
    int arr[] = { 10, 20, 30, 40, 50 }; 
  
    // Print elements of array 
    cout << "Array contains :"; 
    for (int i = 0; i < 5; i++) 
        cout << " " << arr[i]; 
    cout << "\n"; 
  
    // using upper_bound 
    int up1 = upper_bound(arr, arr+5, 35) - arr; 
    int up2 = upper_bound(arr, arr+5, 45) - arr; 
  
    cout << "\nupper_bound for element 35 is at position : " 
              << (up1); 
    cout << "\nupper_bound for element 45 is at position : "
              << (up2); 
    
    return 0; 
}
```
**Output**
```
Vector contains : 10 20 30 40 50

Upper_bound for element 35 is at position : 3
Upper_bound for element 45 is at position : 4

Array contains : 10 20 30 40 50

upper_bound for element 35 is at position : 3
upper_bound for element 45 is at position : 4
```

### `lower_bound()`

The `lower_bound()` function is used to find the lower bound of an element present in a container. That is it finds the location of an element just smaller than a given element in a container. This function accepts the start iterator, end iterator and the element to be checked as parameters and returns the iterator pointing to the lower bound of the element passed as the parameter. If all elements of the container are smaller are less than the element passed, then it returns the last iterator.

**Syntax:**
```cpp
lower_bound(first_itr, last_itr, ele)
```

**Return Value:** Returns an iterator pointing to the lower bound of the element `ele`. That is if `ele` exists in the container, it returns an iterator pointing to `ele` otherwise it returns an iterator pointing to the element just greater than `ele`.

**Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;

// Driver code 
int main() 
{   
    /*** USING lower_bound() ON VECTORS ***/
    
    vector<int> v{ 10, 20, 30, 40, 50 }; 

    // Print vector 
    cout << "Vector contains :"; 
    for (int i = 0; i < v.size(); i++) 
        cout << " " << v[i]; 
    cout << "\n"; 

    vector<int>::iterator low1, low2; 

    // using lower_bound() 
    low1 = lower_bound(v.begin(), v.end(), 20); 
    low2 = lower_bound(v.begin(), v.end(), 55); 

    cout << "\nlower_bound for element 20 at position : " 
         << (low1 - v.begin()); 
    cout << "\nlower_bound for element 55 at position : " 
         << (low2 - v.begin()); 
    
    
    /*** USING lower_bound() ON ARRAYS ***/
    
    int arr[] = { 10, 20, 30, 40, 50 }; 

    // Print elements of array 
    cout << "\n\nArray contains :"; 
    for (int i = 0; i < 5; i++) 
        cout << " " << arr[i]; 
    cout << "\n"; 

    // using lower_bound()
    int lb1 = lower_bound(arr, arr + 5, 20) - arr; 
    int lb2 = lower_bound(arr, arr + 5, 55) - arr;
    
    cout << "\nlower_bound for element 20 is at position : " 
         << (lb1); 
    cout << "\nlower_bound for element 55 is at position : " 
         << (lb2); 
    
    return 0; 
} 
```
**Output**
```
Vector contains : 10 20 30 40 50

lower_bound for element 20 at position : 1
lower_bound for element 55 at position : 5

Array contains : 10 20 30 40 50

lower_bound for element 20 is at position : 1
lower_bound for element 55 is at position : 5
```