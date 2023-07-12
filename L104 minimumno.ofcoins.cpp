//ONLY USING THE RECURSION AND IT'S GIVE THE WRONG ANSWER

// #include <bits/stdc++.h> 
// int solveRec(vector<int> &num,int x){
//     if(x==0){
//         return 0;
//     }
//     if(x<0){
//         return INT_MAX;
//     }
//     int mini = INT_MAX;
//     for(int i=0;i<num.size();i++){
//         int ans = solveRec(num,x-num[i]);
//         if(ans != INT_MAX){
//             mini = min(mini,1+ans);
//         }
//     }
//     return mini;
// }
//int minimumElements(vector<int> &num, int x)
//{
    //Write your code here.
    // int ans = solveRec(num,x);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // else{
    //     return ans;
    // }
//}

//USING DYNAMIC PROGRAMMING (MEMOISATION+RECURSSION)

// #include <bits/stdc++.h> 
// int solveMem(vector<int> &num,int x,vector<int> &dp){
//     if(x==0){
//         return 0;
//     }
//     if(x<0){
//         return INT_MAX;
//     }
//     //step 2
//     if(dp[x]!= -1){
//         return dp[x];
//     }
//     int mini = INT_MAX;
//     for(int i=0;i<num.size();i++){
//         int ans = solveMem(num,x-num[i],dp);
//         if(ans != INT_MAX){
//             mini = min(mini,1+ans);
//         }
//     }
//     dp[x] = mini;
//     return mini;
// }

// int minimumElements(vector<int> &num, int x)
// {
//     //memoisation is used
//     //here x is the amount
//     vector<int> dp(x+1,-1);
//     int ans = solveMem(num,x,dp);
//     if(ans == INT_MAX){
//         return -1;
//     }
//     else{
//         return ans;
//     }
// }

//tABULATION METHOD OD DYNAMIC PROGRAMMING
#include <bits/stdc++.h> 
int solveTab(vector<int> &num,int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    
    for(int i=0;i<=x;i++){
        //i m trying to solve for every amount figure from 1 to x.
        for(int j=0;j<num.size();j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i],1+dp[i-num[j]]); 
            }
        }
    }
    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];

}

int minimumElements(vector<int> &num, int x)
{
    //memoisation is used
    //here x is the amount
    return solveTab(num,x);
}
