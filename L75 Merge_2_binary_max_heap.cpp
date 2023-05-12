// User function Template for C++

class Solution{
    public:
    //
    void heapify(vector<int> &arr , int size , int index)
{
  int largest = index;
  int leftindex = 2*index+1;
  int rightindex = 2*index +2 ;

  if(leftindex < size && arr[largest] < arr[leftindex])
  {
    largest = leftindex ;
    
  }
  if(rightindex < size && arr[rightindex] > arr[largest])
  {
    largest = rightindex;
  }

  if(largest!=index)
  {
    swap(arr[index] , arr[largest]);
    heapify(arr, size , largest);
  }
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step1: merge both array into one
        vector<int> ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        
        //step 2
        int size = ans.size();
        for(int i = size/2-1; i >=0; i--){
        heapify(ans, size, i);
    }
    return ans;
        
    }
};
