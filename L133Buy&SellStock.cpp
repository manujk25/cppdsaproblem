class Solution {
public:
//All the method is same as the Buyy and sell stock 3 the only changes is that it is use k tines which is the ties to buy or sell the stock.



//SPACE OPTIMIZATION


    // int solveSpaceOP(vector<int>& prices , int k){

    //     int n = prices.size();
        
    //     vector<vector<int>> curr(2, vector<int> (k+1, 0));
    //     vector<vector<int>> next(2, vector<int> (k+1, 0));

    //     for(int index = n-1; index>=0; index--){
    //         for(int buy = 0; buy<=1; buy++){
    //             for(int limit=1; limit<=k; limit++){
    //                 int profit = 0;
    //                 if(buy){
    //                     profit = max( (-prices[index] + next[0][limit]), 
    //                                 ( 0 + next[1][limit]) );
    //                 }
    //                 // buy == 0
    //                 else{
    //                     profit = max( (+prices[index] + next[1][limit-1]), 
    //                                 ( 0 + next[0][limit]) );
    //                 }
    //                 curr[buy][limit] = profit;
    //             }
    //         }
    //         next = curr;
    //     }
    //     return next[1][k];
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     return solveSpaceOP(prices,k);




    //RECURSION 



    // int solve(int index , int operationNo , int k , vector<int> & prices){
    //     int n = prices.size();
    //     if(index == n){
    //         return 0;
    //     }
    //     //this is use to buy or sell 
    //     if(operationNo == 2*k){
    //         return 0;
    //     }
    //     int profit = 0 ;
    //     if(operationNo %2 == 0){
    //         profit = max((-prices[index]+solve(index+1,operationNo+1,k,prices)),(0+solve(index+1,operationNo , k , prices)));
    //     }
    //     else{
    //         profit = max((prices[index]+solve(index+1,operationNo+1,k,prices)),(0+solve(index+1,operationNo , k , prices)));
    //     }
    //     return profit;
    // }

    //     int maxProfit(int k, vector<int>& prices) {
    //     return solve(0, 0, k , prices);



        //RECURSION + MEMOISATION


    //         int solveMem(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>> &dp){

    //     if(index == prices.size())
    //         return 0;

    //     if(operationNo == 2*k)
    //         return 0;

    //     if(dp[index][operationNo] != -1)
    //         return dp[index][operationNo];

    //     int profit = 0;
    //     if(operationNo%2 == 0){
    //         // Buy Allowed
    //         profit = max( (-prices[index] + solveMem(index+1, operationNo+1, k, prices, dp)), 
    //                       ( 0 + solveMem(index+1, operationNo, k, prices, dp)) );
    //     }

    //     // Buy Not Allowed
    //     else{
    //         profit = max( (+prices[index] + solveMem(index+1, operationNo+1,k, prices, dp)), 
    //                       ( 0 + solveMem(index+1, operationNo, k, prices, dp)) );
    //     }

    //     return dp[index][operationNo] = profit;
    // }
    //    int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int> (2*k, -1));
    //     return solveMem(0, 0, k, prices, dp);




    // int solveTab(int k, vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
    //     for(int index = n-1; index>=0; index--){
    //         for(int operationNo = 0; operationNo<2*k; operationNo++){
    //             int profit = 0;
    //             if(operationNo%2 == 0){
    //                 // Buy Allowed
    //                 profit = max( (-prices[index] + dp[index+1][operationNo+1]), 
    //                             ( 0 + dp[index+1][operationNo]) );
    //             }
    //             // Buy Not Allowed
    //             else{
    //                 profit = max( (+prices[index] + dp[index+1][operationNo+1]), 
    //                             ( 0 + dp[index+1][operationNo]) );
    //             }
    //             dp[index][operationNo] = profit;
    //         }
    //     }
    //     return dp[0][0];
    // }
    //    int maxProfit(int k, vector<int>& prices) {
    //     // TABULATION
    //     return solveTab(k, prices);


    int solveSpaceOP(int k, vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);
        for(int index = n-1; index>=0; index--){
            for(int operationNo = 0; operationNo<2*k; operationNo++){
                int profit = 0;
                if(operationNo%2 == 0){
                    profit = max( (-prices[index] + next[operationNo+1]), 
                                ( 0 + next[operationNo]) );
                }else{
                    profit = max( (+prices[index] + next[operationNo+1]), 
                                ( 0 + next[operationNo]) );
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        // SPACE OPTIMIZATION
        return solveSpaceOP(k, prices);

    }
};
