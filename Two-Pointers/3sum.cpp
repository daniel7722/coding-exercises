#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;

        int s = 0, l = nums.size() - 1;
        while (s < l && nums[s] <= 0) {
            int target = -nums[s];
            int front = s + 1, rear = l;
            while (front < rear) {
                int sum = nums[front] + nums[rear];
                if (sum > target) {
                    rear--;
                } else if (sum < target) {
                    front++;
                } else {
                    ans.push_back({nums[s], nums[front], nums[rear]});
                    int i = 1;
                    while (front + i < rear && nums[front + i] == nums[front]) {
                        i++;
                    }
                    front += i;
                    i = 1;
                    while (rear - i > front && nums[rear - i] == nums[rear]) {
                        i++;
                    }
                    rear -= i;
                }
            }
            int i = 1;
            while (s + i < l && nums[s + i] == nums[s]) {
                i++;
            }
            s += i;
        }

        return ans;
    }
};