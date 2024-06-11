#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int arr[1001];
        for (int i = 0; i < 1001; i++) {
            arr[i] = 0;
        }
        for (int i: arr1) {
            arr[i]++;
        }

        vector<int> ans;
        for (int i: arr2) {
            while (arr[i] > 0) {
                ans.push_back(i);
                arr[i]--;
            }
        }

        for (int i = 0; i < 1001; i++) {
            while (arr[i] > 0) {
                ans.push_back(i);
                arr[i]--;
            }
        }
        return ans;
    }
};