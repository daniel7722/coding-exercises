#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        unordered_map<int, queue<int>> reverse_mp;
        for (auto it : mp) {
            reverse_mp[it.second].push(it.first);
        }
        priority_queue<int> pq;
        for (auto it : reverse_mp) {
            pq.push(it.first);
        }

        vector<int> ans;
        while (k != 0) {
            int key = pq.top();
            ans.push_back(reverse_mp[key].front());
            k--;
            reverse_mp[key].pop();
            if (reverse_mp[key].empty()) {
                pq.pop();
            }
        }
        return ans;
    }
};