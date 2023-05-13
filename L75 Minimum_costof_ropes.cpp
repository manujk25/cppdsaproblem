class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // create a heap
    long long cost=0,x,y;
priority_queue<long long, vector<long long>, greater<long long>>pq;
        
for(int i=0;i<n;i++)
      pq.push(arr[i]);

for(int i=0;i<n-1;i++){
      x= pq.top();
      pq.pop();
      y=pq.top();
      pq.pop();
      cost+=(x+y);
      pq.push(x+y);
 }
   return cost;
    }
};
