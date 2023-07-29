class Solution {
public:

//RECURSION 



// int solve(int index, int buy, vector<int>& prices){
//     if(index == prices.size()){
//         return 0;
//     }
//     int profit = 0;
//     if(buy){
//         profit = max((-prices[index] + solve(index+1, 0,prices)) , (0+ solve(index+1,1,prices)));
//     }
//     else{
//         profit = max((+prices[index] + solve(index+1, 1,prices)) , (0+ solve(index+1,0,prices                                                                                                                                                        )));
//     }
//     return profit;
// }
//     int maxProfit(vector<int>& prices) {
//         return solve(0,1,prices);


//RECURSION + MEMOISATION 



// int solveMem(int index, int buy, vector<int>& prices,vector<vector<int>> &dp){
//     if(index == prices.size()){
//         return 0;
//     }
//     //step 3 
//     if(dp[index][buy] != -1){
//         return dp[index][buy];
//     }
//     int profit = 0;
//     if(buy){               //buy karo portion                        //skip karo portion
//         profit = max((-prices[index] + solveMem(index+1, 0,prices,dp)) , (0+ solveMem(index+1,1,prices,dp)));
//     }
//     else{
//         profit = max((+prices[index] + solve(index+1, 1,prices,dp)) , (0+ solveMem(index+1,0,prices,dp)));
//     }
//     return dp[index][buy] = profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solveMem(0,1,prices,dp);



//TABULATION
// int solveTab(vector<int>& prices){
//           int n = prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2,0));
//         dp[n][0] = 0;
//         dp[n][1] = 0;
//         for(int i=n-1;i>=0;i--){
//             for(int j=1;j>=0;j--){
//                 int profit = 0;
//                 if(j==0)
//                     profit = max(-prices[i]+dp[i+1][1],dp[i+1][0]);
//                 else
//                     profit = max(prices[i]+dp[i+1][0],dp[i+1][1]);
                
//                 dp[i][j] = profit;
//             }
//         }
//         return dp[0][0];
// }
//     int maxProfit(vector<int>& prices) {
//         return solveTab(prices);

//SPACE OPTIMIZATION
int solveSO(vector<int>& prices){
    int n = prices.size();
    vector<int> curr(2,0);
    vector<int> next(2,0);

        for(int index=n-1;index >= 0;index--){
            for(int buy=0;buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[index]+next[0]),(0+next[1]));
                }else{
                    profit = max((prices[index]+next[1]),(0+next[0]));
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
}
    int maxProfit(vector<int>& prices) {
        return solveSO(prices);


    }
};
