class Solution {
public:



//RECURSION 



    // int numTrees(int n) {
    //     if(n<=1){
    //         return 1;
    //     }
    //     int ans =0;
    //     //think i as root node
    //     for(int i=1;i<=n;i++){
    //         ans += numTrees(i-1)* numTrees(n-i);
    //     }
    //     return ans;




// RECURSION + MEMOISATION




    // int solveMem(int n,vector<int> &dp){
    //     if(n<=1){
    //         return 1;
    //     }
    //     //step 3 
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     int ans =0;
    //     //think i as root node
    //     for(int i=1;i<=n;i++){
    //         ans += solveMem(i-1,dp)* solveMem(n-i,dp);
    //     }
    //     return dp[n] = ans;
    // }
    //     int numTrees(int n) {
    //         vector<int> dp(n+1,-1);
    //         return solve(n,dp);



    //TABULATION METHOD
        int solveTab(int n){
            vector<int> dp(n+1,0);
            dp[0]= 1;
            dp[1] = 1;

            //i-> number of nodes
            for(int i=2;i<=n;i++){
                //j--> root node
                for(int j=1;j<=i;j++){
                    dp[i] += dp[j-1]* dp[i-j];
                }
            }
            return dp[n];
    }
        int numTrees(int n) {
            return solveTab(n); 
    }
};
