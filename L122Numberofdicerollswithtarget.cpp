//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  //RECURSSION 
  
  
  
  
//   long long solve(int dice , int faces , int target){
//       //base case
//       if(target < 0 ){
//           return 0;
//       }
//       if(dice == 0 && target != 0){
//           return 0;
//       }
//       if(target == 0 && dice != 0){
//           return 0;
//       }
//       if(dice == 0 &&  target == 0){
//          return 1; 
//       }
//       long long ans = 0 ;
//       for(int i=1;i<=faces ;i++){
//             ans = ans + solve(dice-1,faces, target-i);
//       }
//       return ans;
//   }
//     long long noOfWays(int M , int N , int X) {
//         // code here
//         return solve(N, M , X);



//RECURSION + MEMOISATION 



//  long long solveMem(int faces, int dice, int tar,  vector<vector<long long>>& dp){
//       if(tar<0){
//           return 0;
//       }
//       if(dice==0 && tar!=0){
//           return 0;
//       }
//       if(tar==0 && dice!=0){
//           return 0;
//       }
//       if(dice==0 && tar==0){
//           return 1;
//       }
      
//       if( dp[dice][tar]!=-1){
//           return  dp[dice][tar];
//       }
//       long long ans = 0;
//       for(int i=1; i<=faces ;i++){
//           ans = ans + solveMem(faces, dice-1, tar-i, dp);
//       }
//       dp[dice][tar] = ans;
//       return  dp[dice][tar];
      
//   }
  
//     long long noOfWays(int M , int N , int X) {
//         vector<vector<long long>> dp(N+1, vector<long long >(X+1, -1));
//         return solveMem(M,N,X,dp);
      
      
        
        //TABULATION
        
        
        
        
    //     long long solveTab(int d, int f, int t){
    //     vector<vector<long long >>dp(d+1,vector<long long >(t+1,0));
    //     dp[0][0]=1;
    //     for(int dice=1; dice<=d; dice++){
    //         for(int target=1; target<=t; target++){
    //             long long ans=0;
    //             for(int i=1; i<=f; i++){
    //                 if(target-i>=0)
    //                     ans+=dp[dice-1][target-i];
    //             }
    //             dp[dice][target]=ans;
    //         }
    //     }
    //     return dp[d][t];
    // }
    // long long noOfWays(int M , int N , int X){
    //     return solveTab(N,M,X);
    
    //space optimization
    
        long long solveTab(int d, int f, int t){
        vector<long long > prev(t+1,0);
        vector<long long > curr(t+1,0);
        
        //after analysing base case
        prev[0]=1;
        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                long long ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i>=0)
                        ans+=prev[target-i];
                }
                curr[target]=ans;
            }
            prev = curr;
        }
        return prev[t];
    }
    long long noOfWays(int M , int N , int X){
        return solveTab(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
