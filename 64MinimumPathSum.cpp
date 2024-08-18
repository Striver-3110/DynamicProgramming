#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int solveDP(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return dp[i][j] = grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX;
        int right = INT_MAX;
        if(i+1 < grid.size())
            down = grid[i][j] + solveDP(i+1, j, grid, dp);
        if(j+1 < grid[0].size())
            right = grid[i][j] + solveDP(i, j+1, grid, dp);
        return dp[i][j] = min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solveDP(0,0, grid, dp);
        return dp[0][0];
    }
};


int main() {
    // Example test case
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution sol;
    int result = sol.minPathSum(grid);
    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}