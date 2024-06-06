
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded += s;
            encoded += ";";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string word;
        for (char c : s) {
            if (c != ';') {
                word.push_back(c);
            } else {
                decoded.push_back(word);
                word = "";
            }
        }
        return decoded;
    }
};
