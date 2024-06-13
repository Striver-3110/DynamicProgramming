#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    long long sum = 0;
    for (auto& a : nums) {
      sum += a;
    }
    if (sum % 2 != 0) {
      return false;
    }

    int half_sum = sum / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(half_sum + 1, false));

    // Base cases
    for (int i = 0; i <= n; i++) {
      dp[i][0] = true; // Can always form sum 0 using no elements
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= half_sum; j++) {
        if (nums[i - 1] > j) {
          dp[i][j] = dp[i - 1][j]; // Exclude the current element if it's bigger
        } else {
          // Include or exclude the current element
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[n][half_sum];
  }
};

// Example usage
int main() {
  vector<int> nums = {1, 5, 11, 5};
  Solution solution;
  bool can_partition = solution.canPartition(nums);
  cout << can_partition << endl; // Output: 1 (true)
  return 0;
}
