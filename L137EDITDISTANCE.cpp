class Solution {
public:

//RECURSION 



// int solve(string &a , string &b , int i , int j){
//     int n1 = a.length();
//     int n2 = b.length();
//     //basse case
//     if(i == n1){
//         return n2-j;
//     }
//     if(j == n2){
//         return n1-i;
//     }
//     int ans = 0 ;
//     if(a[i] == b[j]){
//         return solve(a,b,i+1,j+1);
//     }else{
//         //insert
//         int insertAns = 1+ solve(a,b,i,j+1); 

//         //delete
//         int deleteAns = 1 +  solve(a,b,i+1,j);

//         //replace
//         int replaceAns = 1+ solve(a,b,i+1,j+1);

//         ans = min(insertAns, min(deleteAns,replaceAns));
//     }
//     return ans;
// }
//     int minDistance(string word1, string word2) {
//         return solve(word1,word2,0,0);




        //RECURSION + MEMOISATION 




// int solveMem(string &a , string &b , int i , int j,vector<vector<int> > &dp){
//     int n1 = a.length();
//     int n2 = b.length();
//     //basse case
//     if(i == n1){
//         return n2-j;
//     }
//     if(j == n2){
//         return n1-i;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int ans = 0 ;
//     if(a[i] == b[j]){
//         return solveMem(a,b,i+1,j+1,dp);
//     }else{
//         //insert
//         int insertAns = 1+ solveMem(a,b,i,j+1,dp); 

//         //delete
//         int deleteAns = 1 +  solveMem(a,b,i+1,j,dp);

//         //replace
//         int replaceAns = 1+ solveMem(a,b,i+1,j+1,dp);

//         ans = min(insertAns, min(deleteAns,replaceAns));
//     }
//     return dp[i][j] = ans;
// }
//     int minDistance(string word1, string word2) {
//         vector<vector<int> > dp(word1.length(),vector<int> (word2.length(),-1));
//         return solveMem(word1,word2,0,0,dp);



        //TABULATION 



//     int solveTab(string &a , string &b){
//         int n = a.length();
//         int m = b.length();
//         vector<vector<int>> dp(a.length()+1,vector<int> (b.length()+1,0));
//         for(int i = 0;i<=n;i++){
//             dp[i][0] = i;
//         }
//         for(int j = 0;j<=m;j++){
//             dp[0][j] = j;
//         }
//         for(int i =1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
//                 else{
//                     int del = 1 + dp[i][j-1];
//                     int update = 1 + dp[i-1][j];
//                     int replace = 1 + dp[i-1][j-1];
//                     dp[i][j] = min(del,min(update,replace));
//                 }
//             }
//         }
//         return dp[n][m];

// }
//     int minDistance(string word1, string word2) {
//         return solveTab(word1,word2);




//SPACE OPTIMIZATION
   int solveSpaceOP(string &a , string &b){
          int n = a.length();
        int m = b.length();
        vector<int> prev(m+1,0), cur(m+1,0);
        
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        
        for(int i=1;i<n+1;i++){
            cur[0]=i;
            for(int j=1;j<m+1;j++){
                if(a[i-1]==b[j-1]){
                    cur[j] = prev[j-1];
                }else{
                    cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
                }
            }
            prev = cur;
        }
        return prev[m];
}
    int minDistance(string word1, string word2) {
        return solveSpaceOP(word1,word2);
    }
};
