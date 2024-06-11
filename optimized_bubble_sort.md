# **OPTIMIZED CODE FOR BUBBLE SORT**

```cpp
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[i] > arr[j + 1]){
                swap(arr[i], arr[j + 1]); swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
```