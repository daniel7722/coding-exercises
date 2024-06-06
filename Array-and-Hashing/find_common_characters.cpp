#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp;
        for (char& c : words[0]) {
            mp[c]++;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> mp2;
            for (char& c : words[i]) {
                mp2[c]++;
            }

            for (auto it : mp2) {
                if (it.second < mp[it.first]) {
                    mp[it.first] = it.second;
                }
            }

            for (auto& it : mp) {
                if (it.second > mp2[it.first]) {
                    it.second = 0;
                }
            }
        }
        vector<string> ans;
        for (auto it : mp) {
            for (int i = 0; i < it.second; i++) {
                string cs(1, it.first);
                ans.push_back(cs);
            }
        }
        return ans;
    }
};