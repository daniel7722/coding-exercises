#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0, rear = numbers.size() - 1;

        while (rear > front) {
            int sum = numbers[front] + numbers[rear];
            if (sum > target) {
                rear--;
            } else if (sum < target) {
                front++;
            } else {
                break;
            }
        }
        return {front + 1, rear + 1};
    }
};