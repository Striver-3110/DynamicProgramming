//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define mod 1000000007

class Solution {
public:
    // Iterative approach
    // TC: O(n), SC: O(1)
    int helper(int &n) {
        // base cases
        if(n == 0 || n == 1 || n == 2) {
            return 1;
        }
        
        int first = 1;
        int second = 1;
        int third = 1;
        int forth = 0;
        
        for(int i = 3; i <= n; i++) {
            forth = (first + second) % mod;
            first = second;
            second = third;
            third = forth;
        }
        return third;
    }

    // Dynamic programming approach
    // TC: O(n), SC: O(n)
    int helperDp(int &n, vector<int>& dp) {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i-2] + dp[i-3]) % mod;
        }
        return dp[n];
    }

    // Simple recursion
    // TC: O(2^n), SC: O(n) for the recursion stack
    int helperRecursion(int n) {
        if (n < 0) return 0;
        if(n >= 0 && n <= 2) {
            return 1;
        }
        return (helperRecursion(n-2) + helperRecursion(n-3)) % mod;
    }

    // Recursion with memoization
    // TC: O(n), SC: O(n) for the dp array and recursion stack
    int helperRecursionMemoization(int n, vector<int>& dp) {
        if (n < 0) return 0;
        if(n >= 0 && n <= 2) {
            return dp[n] = 1;
        }
        if(dp[n] != 0) {
            return dp[n];
        }
        return dp[n] = (helperRecursionMemoization(n-2, dp) + helperRecursionMemoization(n-3, dp)) % mod;
    }
    
    int padovanSequence(int n) {
        // code here.
        vector<int> dp(n+1,0);
        // return helper(n);
        // return helperDp(n,dp);
        // return helperRecursion(n);
        return helperRecursionMemoization(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends