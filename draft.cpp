#include <iostream>
#include <vector>
using namespace std;

vector<int> findleader(int arr[], int n) { 
	vector<int> leaders;
	int rightleader = arr [n-1];
	leaders.push_back(rightleader);
	
	
	for (int i = n-2; i >= 0; i--){
		if(arr[i] >= rightleader){
			rightleader = arr[i];
			leaders.push_back(rightleader);
		}
	}
	// print leaders in the correct order -> vector -> i--
	for (int i = leaders.size() - 1; i >= 0; i--){
		cout << leaders[i] << " ";
	}
	return leaders;
}
int main(){
	int n;
	cout << "n= ";
	cin >> n;
	
	int arr[n];
	cout << "arr[]=  ";
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << "Output: ";
	findleader(arr, n);
	
	return 0;
}