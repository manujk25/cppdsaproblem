#include <bits/stdc++.h> 
//coding Studio problem
vector<int> heapify(vector<int> &arr, int i, int n){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
   return arr;
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	for(int i = n/2-1; i >=0; i--){
        heapify(arr, i, n);
    }
    return arr;
}
