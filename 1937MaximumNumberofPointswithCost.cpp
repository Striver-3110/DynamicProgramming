#include <iostream>
#include <vector>
#include <algorithm> // Include this for max_element


using namespace std;



class Solution {
public:
    // n * m * m 
    // long long bruteForce(int r, int c, vector<vector<int>>& points, vector<vector<long long>> &dp){
    //     if(r == points.size()-1) return dp[r][c] = points[r][c];
    //     if(dp[r][c] != -1) return dp[r][c];

    //     long long min = INT_MIN;
    //     for(int j = 0; j < points[0].size(); j++){
    //         min = std::max(min, points[r][c] + bruteForce(r+1, j, points, dp) - abs(c - j));
    //     }
    //     return dp[r][c] = min;
    // }
    // long long maxPoints(vector<vector<int>>& points) {
    //     vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(),-1));
    //     for(int i = 0; i < points[0].size(); i++){
    //         bruteForce(0, i, points, dp);
    //     }
    //     long long max = INT_MIN;
    //     for(int i = 0; i < dp[0].size(); i++){
    //         max = std::max(max, dp[0][i]);
    //     }
    //     return max;
    // }

    // n*m*m TLE
    // long long maxPoints(vector<vector<int>>& points) {
    //     int n = points.size();
    //     int m = points[0].size();
    //     vector<vector<long long>> dp(n, vector<long long>(m, 0));
    //     for(int i = 0; i < m; i++){
    //         dp[0][i] = points[0][i];
    //     }

    //     for(int i = 1; i < n; i++){
    //         for(int k = 0; k < m; k++){
    //             for(int j = 0; j < m; j++){
    //                 dp[i][k] = max(dp[i][k] , dp[i-1][j] + points[i][k] - abs(j-k));
    //             }
    //         }
    //     }
    //     long long ans = -1;
    //     // for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             ans = max(ans, dp[n-1][j]);
    //             // cout<<dp[i][j]<<" ";
    //         }
    //         // cout<<endl;
    //     // }
    //     return ans;
    // }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> prevDP(points[0].begin(), points[0].end());

        vector<long long> left(points[0].begin(), points[0].end());
        vector<long long> right(points[0].begin(), points[0].end());
        for(int i = 1; i < n; i++){
            left[0] = prevDP[0];
            for(int j = 1; j < m; j++){
                left[j] = max(left[j-1]-1, prevDP[j]);
            }

            right[m-1] = prevDP[m-1];
            for(int j = m-2; j >= 0; j--){
                right[j] = max(right[j+1]-1, prevDP[j]);
            }
            
            for(int j = 0; j < m; j++){
                prevDP[j] = points[i][j] + max(left[j], right[j]);
            }
        }
         return *max_element(begin(prevDP), end(prevDP));
    }
};


int main() {
    // Example test case
    vector<vector<int>> points = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1}
    };

    Solution sol;
    long long result = sol.maxPoints(points);
    cout << "Maximum Points: " << result << endl;

    return 0;
}





































