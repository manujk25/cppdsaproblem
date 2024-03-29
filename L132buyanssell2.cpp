class Solution {
public:



//RECURSION 



    // int solve(int index, int buy, vector<int>& prices, int limit){
    //     if(index == prices.size())
    //         return 0;

    //     if(limit == 0)
    //         return 0;

    //     int profit = 0;
    //     if(buy){
    //          profit = max( (-prices[index] + solve(index+1, 0, prices, limit)), ( 0 + solve(index+1, 1, prices, limit)) );
    //     }else{
    //         profit = max( (+prices[index] + solve(index+1, 1, prices, limit-1)), ( 0 + solve(index+1, 0, prices, limit)) );
    //     }
    //     return profit;
    // }
    //    int maxProfit(vector<int>& prices) {
    //     return solve(0, 1, prices, 2);




    //RECURSION + MEMOISATION 



    // int solveMem(int index, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int limit){
    //     if(index == prices.size())
    //         return 0;

    //     if(limit == 0)
    //         return 0;

    //     if(dp[index][buy][limit] != -1)
    //         return dp[index][buy][limit];

    //     int profit = 0;

    //     if(buy){

    //         profit = max( (-prices[index] + solveMem(index+1, 0, prices, dp, limit)), 
    //                       ( 0 + solveMem(index+1, 1, prices, dp, limit)) );
    //     }

    //     // buy == 0
    //     else{
    //         profit = max( (+prices[index] + solveMem(index+1, 1, prices, dp, limit-1)), 
    //                       ( 0 + solveMem(index+1, 0, prices, dp, limit)) );
    //     }

    //     return dp[index][buy][limit] = profit;
    // }
    //    int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));   // 3D - DP
    //     return solveMem(0, 1, prices, dp, 2);
        




//TABULATION  





    // int solveTab(vector<int>& prices){

    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));   // 3D - DP

    //     for(int index = n-1; index>=0; index--){
    //         for(int buy = 0; buy<=1; buy++){
    //             for(int limit=1; limit<=2; limit++){
    //                 int profit = 0;
    //                 if(buy){
    //                     profit = max( (-prices[index] + dp[index+1][0][limit]), 
    //                                 ( 0 + dp[index+1][1][limit]) );
    //                 }else{
    //                     profit = max( (+prices[index] + dp[index+1][1][limit-1]), 
    //                                 ( 0 + dp[index+1][0][limit]) );
    //                 }
    //                 dp[index][buy][limit] = profit;
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }
    //    int maxProfit(vector<int>& prices) {
    //     // TABULATION
    //     return solveTab(prices);



//SPACE OPTIMISATION



    int solveSpaceOP(vector<int>& prices){

        int n = prices.size();
        
        vector<vector<int>> curr(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
                    int profit = 0;
                    if(buy){
                        profit = max( (-prices[index] + next[0][limit]), 
                                    ( 0 + next[1][limit]) );
                    }
                    // buy == 0
                    else{
                        profit = max( (+prices[index] + next[1][limit-1]), 
                                    ( 0 + next[0][limit]) );
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {

        // SPACE OPTIMIZATION
        return solveSpaceOP(prices);
    }
};
