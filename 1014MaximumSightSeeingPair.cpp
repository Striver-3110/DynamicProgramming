#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int prev = values[0];
        for(int j = 1; j < n; j++){
            ans = max(ans,prev + values[j]-j);
            prev = max(prev, values[j]+j);
        }
        return ans;
    }
};


int main() {
    // Example test case
    vector<int> values = {8, 1, 5, 2, 6};

    Solution sol;
    int result = sol.maxScoreSightseeingPair(values);
    cout << "Maximum Score of Sightseeing Pair: " << result << endl;

    return 0;
}
