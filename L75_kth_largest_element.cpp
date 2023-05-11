//User function template for C++
//kth largest element using Min heap ....
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    //step 1  create a min heap
	     priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        //step 2 
        vector<int>vec;
         for(int i=0;i<k;i++)
        {
            int temp = pq.top();
            vec.push_back(temp);
            pq.pop();
        }
    //step 3 
        // int ans = pq.top();
        return vec;
	}

};
