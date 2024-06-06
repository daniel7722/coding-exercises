#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> f(size, 1), b(size, 1);
        for (int i = 0; i < size - 1; i++) {
            f[i + 1] = nums[i] * f[i];
        }
        for (int i = size - 1; i > 0; i--) {
            b[i - 1] = nums[i] * b[i];
        }

        for (int i = 0; i < size; i++) {
            nums[i] = f[i] * b[i];
        }
        return nums;
    }
};