#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
            mini = std::min(mini, matrix[0][j]);

        }
        if(n == 1){
            return mini;
        }
        int ans = INT_MAX;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int min;
                if(j - 1 >= 0 && j + 1 < m){
                    min = std::min(dp[i-1][j-1],std::min(dp[i-1][j],dp[i-1][j+1]));
                }
                else if(j == 0){
                    min = std::min(dp[i-1][j],dp[i-1][j+1]);
                }else if(j == m-1){
                    min = std::min(dp[i-1][j-1],dp[i-1][j]);
                }
                dp[i][j] = matrix[i][j]+min;
                if(i == n-1)ans = std::min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

auto __init = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


int main() {
    // Example test case
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    Solution sol;
    int result = sol.minFallingPathSum(matrix);
    cout << "Minimum Falling Path Sum: " << result << endl;

    return 0;
}