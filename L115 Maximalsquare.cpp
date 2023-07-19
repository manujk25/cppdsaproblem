//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//RECURSSION
// int solve(vector<vector<int>> mat,int i ,int j,int & maxi){
//     if(i>= mat.size() || j >= mat[0].size()){
//         return 0;
//     }
//     int right = solve(mat,i,j+1,maxi);
//     int diagonal = solve(mat , i+1 , j+1,maxi);
//     int down = solve(mat,i+1,j,maxi);
    
//     if(mat[i][j] == 1){
//         int ans = 1+ min(right , min(diagonal , down));
//         maxi = max(maxi,ans); 
//         return ans;
//     }
//     else{
//         return 0;
//     }
// }
//     int maxSquare(int n, int m, vector<vector<int>> mat){
//         // code here
//         int maxi = 0;
//         solve(mat,0,0,maxi);
//         return maxi;


//RECURSION + MEMOISATION


// int solveMem(vector<vector<int>>& mat,int i ,int j,int & maxi,vector<vector<int>> &dp){
//     if(i>= mat.size() || j >= mat[0].size()){
//         return 0;
//     }
    
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
    
//     int right = solveMem(mat,i,j+1,maxi,dp);
//     int diagonal = solveMem(mat , i+1 , j+1,maxi,dp);
//     int down = solveMem(mat,i+1,j,maxi,dp);
    
//     if(mat[i][j] == 1){
//         dp[i][j] = 1+ min(right , min(diagonal , down));
//         maxi = max(maxi, dp[i][j]); 
//         return dp[i][j];
//     }
//     else{
//         return dp[i][j] = 0;
//     }
// }
//     int maxSquare(int n, int m, vector<vector<int>> mat){
//         // code here
//         int maxi = 0 ;
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         solveMem(mat,0,0,maxi,dp);
//         return maxi;


//TABULATION


// int solveTab(vector<vector<int>>& mat,int &maxi){
//     int row = mat.size();
//     int col = mat[0].size();
    
//     vector<vector<int> > dp(row+1,vector<int>(col+1,0));
//     for(int i=row-1;i>=0;i--){
//         for(int j=col-1;j>=0;j--){
//           int right = dp[i][j+1];
//           int diagonal = dp[i+1][j+1];
//           int down = dp[i+1][j];
    
//             if(mat[i][j] == 1){
//             dp[i][j] = 1+ min(right , min(diagonal ,down));
//             maxi = max(maxi, dp[i][j]); 
//             }else{
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return dp[0][0];
// }
//     int maxSquare(int n, int m, vector<vector<int>> mat){
//         // code here
//         int maxi = 0 ;
//         solveTab(mat,maxi);
//         return maxi;


//SPACE OPTIMIZATION O(M)

    // int solveSO(vector<vector<int>> &mat,int & maxi)
    // {
    //     int row=mat.size();
    //     int coloumn =mat[0].size();
       
    //     vector<int> current(coloumn+1,0);
    //     vector<int>next (coloumn+1,0);
        
    //     for(int i =row-1;i>=0;i--){
    //         for(int j =coloumn-1;j>=0;j--){
                
    //             int right=current[j+1];
    //             int left=next[j];
    //             int diagonal=next[j+1];
                
    //             if(mat[i][j]==1){
    //                 current[j]=1+min(left,min(right,diagonal));
    //                 maxi=max(current[j],maxi);
    //             }
    //             else{
    //                 current[j]=0;
    //             }
    //         }
    //         next=current;
    //     }
    //     return current[0];
    // }
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     // code here
    //     int maxi = 0 ;
    //     solveSO(mat,maxi);
    //     return maxi;
    
    
    
    //SPACE OPTIMIZATION OD O(1)


void solveSO2(vector<vector<int>> &mat,int & maxi)
    {
        int row=mat.size();
        int coloumn =mat[0].size();
       
       
        
        for(int i =row-1;i>=0;i--){
            for(int j =coloumn-1;j>=0;j--){
                
               
                
                if(mat[i][j]==1 && i<row-1&& j<coloumn-1){
                    
                    mat[i][j]=1+min(mat[i+1][j],min(mat[i][j+1],mat[i+1][j+1]));
                    
                }
                maxi=max(mat[i][j],maxi);
            }
         
        }
        
    }
        int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi = 0 ;
        solveSO2(mat,maxi);
        return maxi;

        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
