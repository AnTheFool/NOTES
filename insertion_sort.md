```cpp
{
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
```

## Time complexity:
- Best case: Already sorted. $O(\log{n})$
- Worst case: Reverse sorted. $O(n^2)$
In general: $O(n^2)$