

//USING RECURSION 


// #include <bits/stdc++.h> 
// #define MOD 1000000007

// int add(int a, int b){
//     return ( (a%MOD) + (b%MOD) )%MOD;
// }

// int mul(int a, int b){
//     return ( ( (a%MOD) * 1LL) * ( (b%MOD) * 1LL) )%MOD;
// }

// int Recursion(int n, int k){
//     // base case
//     if (n == 1) return k;
//     if (n == 2) return add(k, mul(k, k-1));

//     int ans = add( (mul(Recursion(n-2, k), k-1) ), ( (mul(Recursion(n-1, k), k-1) ) ) );
//     return ans;
// }
// int numberOfWays(int n, int k) {
//     // Using Recursion
//     // return Recursion(n, k);

// }




//USING RECURSION AND MEMOISATION



// #include <bits/stdc++.h> 
// #define MOD 1000000007
// int add(int a, int b){
//     return ( (a%MOD) + (b%MOD) )%MOD;
// }
// int mul(int a, int b){
//     return ( ( (a%MOD) * 1LL) * ( (b%MOD) * 1LL) )%MOD;
// }
// int RecurMemo(int n, int k, vector<int> &dp){
//     // base case
//     if (n == 1) return k;
//     if (n == 2) return add(k, mul(k, k-1));
//     if (dp[n] != -1) return dp[n];

//     dp[n] = add( (mul(RecurMemo(n-2, k, dp), k-1) ), ( (mul(RecurMemo(n-1, k, dp), k-1) ) ) );
//     return dp[n];
// }
// int numberOfWays(int n, int k) {

//     // Using Recursion + Memoization
//     vector<int> dp(n+1, -1);
//     return RecurMemo(n, k, dp);
// }



//USING TABULATION 



// #include <bits/stdc++.h> 
// #define MOD 1000000007
// int add(int a, int b){
//     return ( (a%MOD) + (b%MOD) )%MOD;
// }
// int mul(int a, int b){
//     return ( ( (a%MOD) * 1LL) * ( (b%MOD) * 1LL) )%MOD;
// }
// int Tabulation(int n, int k){
//     vector<int> dp(n+1, -1);
//     dp[1] = k;
//     dp[2] = add(k, mul(k, k-1));

//     for (int i=3; i<=n; i++){
//         dp[i] = add( (mul(dp[i-2], k-1)), (mul(dp[i-1], k-1)) );
//     }

//     return dp[n];
// }
// int numberOfWays(int n, int k) {
//     // Using Tabulation
//     return Tabulation(n, k);
// }


//USING SPACE OPTIMASATION 


#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a, int b){
    return ( (a%MOD) + (b%MOD) )%MOD;
}
int mul(int a, int b){
        return ( ( (a%MOD) * 1LL) * ( (b%MOD) * 1LL) )%MOD;
}
  
int Space_Optimize(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for (int i=3; i<=n; i++){
        int ans = add( (mul(prev2, k-1)), (mul(prev1, k-1)) );
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int numberOfWays(int n, int k) {
    // Using Space Optimization
    return Space_Optimize(n, k);
}
