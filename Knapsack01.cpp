//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solve(int wt[], int val[], int n, int W,vector<vector<int>>& dp){
        if(n < 0 || W < 0){
            return 0;
        }
        if(W == 0 || n == 0){
            return 0;
        }
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        if(wt[n-1] > W){
            return dp[n][W] = solve(wt,val,n-1,W,dp);
        }else{
            return dp[n][W] = max(solve(wt,val,n-1,W-wt[n-1],dp)+val[n-1],solve(wt,val,n-1,W,dp));
        }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n)
    { 
       // Your code here
    //   int profit = 0;
    
    // Recursive + Memoization
    // TC --> O(2^n) 
    // SC --> O(nw) // due to dp and recursive calls
        // vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        //   return solve(wt,val,n,W,dp);
    
    
    // Tabular 
    // TC --> O(nw)
    // SC --> O(nw)
    
        int dp[n+1][w+1];
        memset(dp,-1,sizeof(dp));
        
            // initialization
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= w; j++){
                    // either weight is zero or we dont have any item to add into knapsack
                    // then definately the profit will be zero
                    if(i == 0 || j == 0){
                        dp[i][j] = 0;
                    }
                }
            }
            // profit calculation
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= w; j++){
                    if(j < wt[i-1]){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                    }
                }
            }
            return dp[n][w];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends