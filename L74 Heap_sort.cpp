// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
      void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      if(i < 0 || i >= n)
        return;
      int left = 2*i+1;
      int right = 2*i+2;
      int largest = i;
      if(left < n && arr[left] > arr[i])
        largest = left;
      if(right < n && arr[right] > arr[largest])
        largest = right;
      if(largest != i) {
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
      }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
       for(int i=(n-2)/2; i>=0; --i)
          heapify(arr, n, i);
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr, n);
        for(int i=n-1; i>=1; --i) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

