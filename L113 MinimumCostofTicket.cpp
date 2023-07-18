
//RECURSSION

// int allPossCost(int n, vector<int>& days, vector<int>& cost, int index, int pass){
//     // Base Case
//     if(index >= n) return 0;
//     if(days[index] <= pass) return allPossCost(n, days, cost, index + 1, pass);
//     int ans = 0;
//     // 1 day pass
//     ans = cost[0] + allPossCost(n, days, cost, index + 1, days[index]);
//     // 7 days pass
//     ans = min(ans, cost[1] + allPossCost(n, days, cost, index + 1, days[index] + 6));
//     // 30 days pass
//     ans = min(ans, cost[2] + allPossCost(n, days, cost, index + 1, days[index] + 29));
//     return ans;
// }


// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     // Recursive Approach.
//     // Time Complexity: O(3^N)
//     // Space Complexity: O(N)
//     return allPossCost(n, days, cost, 0, 0);
// }



//RECURSION +MEMOISATION


// int allPossCost(int n, vector<int>& days, vector<int>& cost, int index, int pass, vector<int> &dp){
//     // Base Case
//     if(index >= n) return 0;
//     if(days[index] <= pass) return allPossCost(n, days, cost, index + 1, pass, dp);
//     if(dp[index] != -1) return dp[index];
//     int ans = 0;
//     // 1 day pass
//     ans = cost[0] + allPossCost(n, days, cost, index + 1, days[index], dp);
//     // 7 days pass
//     ans = min(ans, cost[1] + allPossCost(n, days, cost, index + 1, days[index] + 6, dp));
//     // 30 days pass
//     ans = min(ans, cost[2] + allPossCost(n, days, cost, index + 1, days[index] + 29, dp));
//     dp[index] = ans;
//     return dp[index];
// }


// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     // DP: Top Down Approach: Recursion + Memoization.
//     // Time Complexity: O(N)
//     // Space Complexity: O(N)
//     //STEP 1
//     vector<int> dp(n, -1);
//     return allPossCost(n, days, cost, 0, 0, dp);
// }



//TABULATION



// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     // Time Complexity: O(N)
//     // Space Complexity: O(N)
//     vector<int> dp(n + 1, INT_MAX/2);
//     dp[n] = 0;
//     for(int i = n - 1; i >= 0; i--){
//         // 1 day pass
//         dp[i] = min(dp[i], dp[i+1] + cost[0]);
//         // 7 day pass
//         int j = i;
//         while(j < n && days[j] < days[i] + 7){
//             j++;
//         }
//         dp[i] = min(dp[i], dp[j] + cost[1]);
//         // 30 day pass
//         j = i;
//         while(j < n && days[j] < days[i] + 30){
//             j++;
//         }
//         dp[i] = min(dp[i], dp[j] + cost[2]);
//     }
//     return dp[0];
// }


//SPACE OPTIMIZATION + QUEUE


int minimumCoins(int n, vector<int> &days, vector<int> &cost)
{
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    queue<pair<int,int>> monthly;
    queue<pair<int,int>> weekly;
    int ans = 0;
    for(int i = 0; i < n; i++){
        // 7 day pass
        while(!weekly.empty() && weekly.front().first + 7 <= days[i]){
            weekly.pop();
        }
        weekly.push(make_pair(days[i], ans + cost[1]));
        // 30 day pass
        while(!monthly.empty() && monthly.front().first + 30 <= days[i]){
            monthly.pop();
        }
        monthly.push(make_pair(days[i], ans + cost[2]));
        // 1 day pass
        ans = min(ans + cost[0], min(weekly.front().second, monthly.front().second));
    }
    return ans;
}
