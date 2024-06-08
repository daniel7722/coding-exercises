#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    /**
     * This approach keeps a remainder of cumulative sum. When there are two remainders
     * that are the same, it means that the sum of the elements between the two remainders
     * is divisible by k.
     * @param nums
     * @param k
     * @return
     */
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> accumulated_mod;
        if (nums.size() < 2) return false;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i > 0 && sum % k == 0) return true;
            if (accumulated_mod.count(sum%k) == 0) {
                accumulated_mod[sum%k] = i;
            } else {
                if (i - accumulated_mod[sum%k] > 1)
                    return true;
            }
        }
        return false;
    }
};