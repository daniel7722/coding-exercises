#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        int current_num = nums[0];
        int current_max = 1, global_max = 1;
        for (int i : nums) {
            if (i - current_num == 1) {
                current_num = i;
                current_max++;
            } else if (current_num == i) {
                continue;
            } else {
                global_max = max(global_max, current_max);
                current_num = i;
                current_max = 1;
            }
        }
        return max(global_max, current_max);
    }
};