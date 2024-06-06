#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int front = 0, rear = heights.size() - 1;
        int ans = 0;
        while (front < rear) {
            ans = max(ans, (rear - front) * min(heights[front], heights[rear]));
            if (heights[front] > heights[rear]) {
                rear--;
            } else {
                front++;
            }
        }
        return ans;
    }
};