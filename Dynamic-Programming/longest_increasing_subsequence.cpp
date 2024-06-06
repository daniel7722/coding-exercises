#include <vector>
using namespace std;

class Solution {
public:
    /**
     * This is Dynamic programming approach
     * Time complexity: O(N^2)
     * Space complexity: O(N)
     * @param nums
     * @return
     */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    /**
     * This is quicker approach with complicated concept which I haven't even grasp fully yet
     * Time complexity: O(Nlog(N))
     * Space complexity: O(N)
     * @param nums
     * @return
     */
    int lengthOfLIS2(vector<int>& nums) {
        vector<int> ans;
        for (int x: nums) {
            if (ans.empty() || x > ans[ans.size()-1]) {
                ans.push_back(x);
            } else {
                auto it = lower_bound(ans.begin(), ans.end(), x);
                *it = x;
            }
        }
        return ans.size();
    }

};