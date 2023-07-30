class Solution {
public:

//RECURSION 



// int solve(string &a , string &b , int i , int j){
//     //base case
//     if(i == a.length()){
//         return 0;
//     }
//     if(j == b.length()){
//         return 0;
//     }
//     int ans =0;
//     if(a[i] == b[j]){
//         ans = 1+ solve(a,b,i+1,j+1);
//     }else{
//         ans = max(solve(a,b,i+1,j), solve(a,b,i,j+1));
//     }
//     return ans;
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         return solve(text1, text2, 0, 0);





//RECURSION + MEMOISATION 




//    int solveMem(string& a, string& b, int i, int j, vector<vector<int>> &dp){
//         // Base Case
//         if(i == a.length())
//             return 0;

//         if(j == b.length())
//             return 0;

//         if(dp[i][j] != -1)
//             return dp[i][j];

//         int ans = 0;

//         if(a[i] == b[j]){
//             ans = 1 + solveMem(a, b, i+1, j+1, dp);
//         }else{
//             ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
//         }
//         return dp[i][j] = ans;
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int> > dp(text1.length()+1,vector<int>(text2.length()+1, -1 ));
//         return solveMem(text1, text2, 0, 0,dp);





        //TABULATION 




    // int solveTab(string& a, string& b){
    //     int n1 = a.length();
    //     int n2 = b.length();

    //     vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

    //     for(int i = n1-1; i>=0; i--){
    //         for(int j = n2-1; j>=0; j--){
    //             int ans = 0;

    //             if(a[i] == b[j]){
    //                 ans = 1 + dp[i+1][j+1];
    //             }else{
    //                 ans = max(dp[i+1][j], dp[i][j+1]);
    //             }
    //             dp[i][j] = ans;
    //         }
    //     } 
    //     return dp[0][0];
    // }
    //     int longestCommonSubsequence(string text1, string text2) {
    //     return solveTab(text1, text2);


    //Space optimization

 int solveSpaceOP(string& a, string& b){

        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        vector<int> currRow(n2+1, 0);
        vector<int> nextRow(n2+1, 0);

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){
                int ans = 0;

                if(a[i] == b[j])
                    ans = 1 + nextRow[j+1];

                else
                {
                    ans = max(nextRow[j], currRow[j+1]);
                }

                currRow[j] = ans;
            }

            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveSpaceOP(text1, text2);
    }
};
