//Recursion

// #define MOD 1000000007
// long long int countDerangements(int n) {
//     //base case 
//     if(n==1){
//         return 0;
//     }
//     if(n==2){
//         return 1;
//     }

//     int ans =( ((n-1)%MOD)* (((countDerangements(n-1))%MOD) + ((countDerangements(n-2))%MOD))%MOD);
//     return ans;
// }


//RECURSION AND MEMOISATION
// #include<bits/stdc++.h>
// #define MOD 1000000007
// long long int solveMem(int n , vector<long long int>&dp){
//     //base case 
//     if(n==1){
//         return 0;
//     }
//     if(n==2){
//         return 1;
//     }
//     //Step 3
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     //step 2
//     dp[n] =( ((n-1)%MOD)* (((solveMem(n-1,dp))%MOD) + ((solveMem(n-2,dp))%MOD))%MOD);
//     return dp[n];
// }
// long long int countDerangements(int n) {
//     //step 1
//      vector<long long int> dp(n+1,-1);
//      return solveMem(n,dp);
// }

//TABULATION METHOD
#include<bits/stdc++.h>
#define MOD 1000000007
long long int solveTab(int n ){
    //base case 
    vector<long long int>dp(n+1,0);
    dp[1] = 0;
    dp[2] =1;

    for(int i=3;i<=n;i++){
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] %MOD;
        long long int sum = (first+second)%MOD;

        long long int ans = ((i-1)*sum)%MOD;
        dp[i] = ans;  
    }
    return dp[n];
    
}
long long int countDerangements(int n) {
    //step 1
    return solveTab(n);
}
