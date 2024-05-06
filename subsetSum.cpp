//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int> arr,int n, int sum, vector<vector<bool>>& dp){
        if(n <= 0 && sum > 0){
            return false;
        }
        if(sum == 0){
            return dp[n][sum] = true;
        }
        if(sum < 0){
            return false;
        }
        if(dp[n][sum])return dp[n][sum];
        if(arr[n-1] > sum){
            return dp[n][sum] = solve(arr,n-1,sum,dp);
        }else{
            return dp[n][sum] = (solve(arr,n-1,sum-arr[n-1],dp) || solve(arr,n-1,sum,dp));
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // bool dp[size(arr)+1][sum+1];
        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        // Recursive + Memoization
        // TC: O(2^n)
        // SC: O(nsum)
        // causes TLE
            // memset(dp,false,sizeof(dp));
            // return solve(arr,n,sum,dp);
        
        // Tabular method 
        // TC: O(n.sum)
        // SC: O(n.sum)
        
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= sum; j++){
                    if(i == 0){
                        dp[i][j] = false;
                    }
                    if(j == 0){
                        dp[i][j] = true;
                    }
                }
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= sum; j++){
                    if(j < arr[i-1]){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
            
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends