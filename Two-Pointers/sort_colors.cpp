#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    /**
     * This is a basic approach that use frequency map to sort the array
     * @param nums
     */
    void sortColors(vector<int> &nums) {
        unordered_map<int, int> mp;

        for (int i: nums) {
            mp[i]++;
        }

        int i = 0, len = nums.size();
        for (int j = 0; j < 3; j++) {
            while (i < len && mp[j] > 0) {
                nums[i++] = j;
                mp[j]--;
            }
        }
    }

    /**
     * This approach is one-pass and make use of three pointers to keep track
     * @param nums
     */
    void sortColors2(vector<int> &nums) {
        const char red = 0, white = 1, blue = 2;
        int l = 0, m = 0, r = nums.size() - 1;// pointers to partition
        while (m <= r) {
            switch (nums[m]) {
                case red:
                    swap(nums[l], nums[m]);
                    l++, m++;
                    break;
                case white:
                    m++;
                    break;
                case blue:
                    swap(nums[m], nums[r]);
                    r--;
            }
        }
    }
};