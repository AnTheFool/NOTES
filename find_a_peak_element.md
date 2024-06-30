# **FIND A PEAK ELEMENT**

## ***Problem statement***

Given an array, find the peak element. A peak element is an element where it's higher than the surrounded elements

Sample input 1:

Input | Output
|:-----------------------------|:--------------------------------|
5 10 20 15 7 | 20
10 20 15 5 23 90 67 | 20 or 90
80 70 60 | 80

## ***Naive solution***
```cpp
int get_peak(int arr[], int n){
    if (n == 1) return arr[0];
    if (arr[0] >= arr[1]) return arr[0];
    if (arr[n - 1] >= arr[n - 2]) return arr[n - 1];
    for (int i = 1; i < n - 1; i++){
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
}
```
Time complexity: Worse case $O(\log{n})$

## ***Efficient solution***
```cpp
int getPeak(int arr[], int n)
{
	int low = 0, high = n - 1;

		while(low <= high)
		{
			int mid = (low + high) / 2;

			if((mid == 0 || arr[mid - 1] <= arr[mid]) &&
				(mid == n - 1 || arr[mid + 1] <= arr[mid]))
				return mid;
			if(mid > 0 && arr[mid - 1] >= arr[mid])
				high = mid -1;
			else
				low = mid + 1;
		}
	return -1;
}
```

Time complexity: $O(\log{n})$