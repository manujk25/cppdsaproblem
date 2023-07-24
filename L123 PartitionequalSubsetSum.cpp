//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// Recursion 
    
    // bool solve(int index,int arr[],int N,int target)
    // {
    //     // base case
    //     if(index>=N)
    //     {
    //         return 0;
    //     }
        
    //     if(target<0)
    //     {
    //         return 0;
    //     }
    //     if(target==0)
    //     {
    //         return 1;
    //     }
        
    //     bool include=solve(index+1,arr,N,target-arr[index]);
        
    //     bool exclude=solve(index+1,arr,N,target);
        
    //     return include or exclude;
    // }
    //     int equalPartition(int N, int arr[])
    // {
    //     int total=0;
    //     for(int i=0;i<N;i++)
    //     {
    //         total+=arr[i];
    //     }
        
    //     if(total%2!=0)
    //     {
    //         return 0;
    //     }
        
    //     int target=total/2;
        
    //     return solve(0,arr,N,target);
        
    
    
    
    // Recursion + Memoization
    
    
    
    
    // bool solveMem(int index,int arr[],int N,int target,vector<vector<int>> &dp)
    // {
    //     // base case
    //     if(index>=N)
    //     {
    //         return 0;
    //     }
    //     if(target<0)
    //     {
    //         return 0;
    //     }
    //     if(target==0)
    //     {
    //         return 1;
    //     }
        
    //     if(dp[index][target]!=-1) 
    //     {
    //         return dp[index][target];
    //     }
        
    //     bool include=solveMem(index+1,arr,N,target-arr[index],dp);
        
    //     bool exclude=solveMem(index+1,arr,N,target,dp);
        
    //     return dp[index][target]=include or exclude;
    // }
    //     int equalPartition(int N, int arr[])
    // {
    //     int total=0;
    //     for(int i=0;i<N;i++)
    //     {
    //         total+=arr[i];
    //     }
        
    //     if(total%2!=0)
    //     {
    //         return 0;
    //     }

        
    //     vector<vector<int>> dp(N+1,vector<int>(target+1,-1));
    //     return solveMem(0,arr,N,target,dp);
        
   
   
   
    
    // Tabulation
    
    
    
    
    
    // bool solveTab(int arr[],int N,int total)
    // {
    //     vector<vector<int>> dp(N+1,vector<int>(total+1,0));
        
    //     // after analyzing base case
    //     for(int i=0;i<=N;i++)
    //     {
    //         dp[i][0]=1;
    //     }
        
    //     for(int index=N-1;index>=0;index--)
    //     {
    //         for(int target=0;target<=total/2;target++)
    //         {
    //             bool include=0;
                
    //             if(target-arr[index]>=0){
    //             include=dp[index+1][target-arr[index]];
    //             }
    //             bool exclude=dp[index+1][target];
                
    //             dp[index][target]=include or exclude;
    //         }
    //     }
        
    //     return dp[0][total/2];
        
    // }
    //     int equalPartition(int N, int arr[])
    // {
    //     int total=0;
    //     for(int i=0;i<N;i++)
    //     {
    //         total+=arr[i];
    //     }
        
    //     if(total%2!=0)
    //     {
    //         return 0;
    //     }
        
    //     int target=total/2;
        
    //     return solveTab(arr,N,total);
      
      
      
        
    
    // Space Optimization
    
    
    
    bool solveSpace(int arr[],int N,int total)
    {
        vector<int> curr(total/2 +1,0);
        vector<int> next(total/2 +1,0);
        
        curr[0]=1;
        next[0]=1;
        
        
        for(int index=N-1; index>=0; index--)
        {
            for(int target=0; target<=total/2; target++)
            {
                bool include=0;
                
                if(target-arr[index]>=0)
                {
                    include=next[target-arr[index]];
                }
                
                bool exclude=next[target];
                
                curr[target]=include or exclude;
                
            }
            next=curr;
        }
        
        return next[total/2];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total=0;
        for(int i=0;i<N;i++)
        {
            total+=arr[i];
        }
        
        if(total%2!=0)
        {
            return 0;
        }
        
        int target=total/2;
        vector<vector<int>> dp(N+1,vector<int>(target+1,-1));
        return solveSpace(arr,N,total);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
