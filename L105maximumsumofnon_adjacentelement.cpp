//USING THE RECURSION

// #include <bits/stdc++.h> 
// int solveRec(vector<int> & nums,int n){
//     //base case
//     if(n<0){
//         return 0;
//     }

//     if(n==0){
//         return nums[0];
//     }

//     //Abb yaha se do case banegeay either include hoga ya toh exclude hoga
//     int include = solveRec(nums,n-2)+nums[n];
//     int exclude = solveRec(nums,n-1)+0;

//     return max(include,exclude);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
//     int ans = solveRec(nums,n-1);
//     return ans;
// }

//BY USING RECURSION AND MEMOISATION
//it also give the Time limit exceed so we use the tabulation method to solve the problem
// #include <bits/stdc++.h> 
// int solveMem(vector<int> & nums,int n,vector<int> &dp){
//     //base case
//     if(n<0){
//         return 0;
//     }

//     if(n==0){
//         return nums[0];
//     }

//     //step 2
//     if(dp[n] != -1){
//         return dp[n];
//     }
    
//     //Abb yaha se do case banegeay either include hoga ya toh exclude hoga
//     int include = solveMem(nums,n-2)+nums[n];
//     int exclude = solveMem(nums,n-1)+0;

//     //step 3
//     dp[n] = max(include,exclude);
//     return dp[n];
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//      int n = nums.size();
//      //step 1
//      vector<int> dp(n,-1);
//      solveMem(nums,n-1,dp)
// }


//TABULATION  
//Time complexity is O(n).
//space Complexity is O(n).
// #include <bits/stdc++.h> 
// int solveTab(vector<int> & nums,int n){

//     vector<int> dp(n,0);
//     dp[0] = nums[0];

//     for(int i=1;i<n;i++){ 
//         int include = dp[i-2]+nums[i];
//         int exclude = dp[i-1]+0;

//         dp[n] = max(include,exclude);
//     }
//     return dp[n-1];

// }
// int maximumNonAdjacentSum(vector<int> &nums){
//      int n = nums.size();
//      //step 1
//      vector<int> dp(n,-1);
//      solveTab(nums,n-1);
// }


//Space optimization of the tabulation method;
//time complexity is O(n).
//Space Complexity is O(1).
#include <bits/stdc++.h> 
int solveSop(vector<int> & nums){
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1;i<n;i++){ 
        int include = prev2+nums[i];
        int exclude = prev1+0;
        int ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;

}
int maximumNonAdjacentSum(vector<int> &nums){
     int n = nums.size();
     //step 1
     solveSop(nums);
}
