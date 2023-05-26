//coding studion Solutiion
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    for(int i=0; i<arr[0].size(); i++){
        char ch = arr[0][i];

        bool match = true;

        for(int j=1; j<n; j++){
            if(arr[1].size()<i || ch != arr[j][i]){
                match = false;
                break;
            } 
            else{
                match = true;
            }
        }
        if(match == false){
                break;
        }
        else{
            ans.push_back(ch);
        }
    }    
    return ans;
}

//Geekforgeek solution

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
    string ans = "";

    for(int i=0; i<arr[0].size(); i++){
        char ch = arr[0][i];

        bool match = true;

        for(int j=1; j<N; j++){
            if(arr[1].size()<i || ch != arr[j][i]){
                match = false;
                break;
            } 
            else{
                match = true;
            }
        }
        if(match == false){
                break;
        }
        else{
            ans.push_back(ch);
        }
    }
    //only one case add into it that if string is Empty 
       if(ans=="")
      return "-1";
      
    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
