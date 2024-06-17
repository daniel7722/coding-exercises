#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        long j = sqrt(c);

        while (i <= j) {
            long sum = pow(i, 2) + pow(j, 2);
            if (sum > c) {
                j--;
            } else if (sum < c) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};