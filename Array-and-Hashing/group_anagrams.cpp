#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }
        for (auto m : mp) {
            ans.push_back(m.second);
        }
        return ans;
    }
};

int main() { return 0; }