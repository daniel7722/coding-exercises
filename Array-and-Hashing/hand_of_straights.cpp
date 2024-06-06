#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for (int& i : hand) {
            mp[i]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            while (it->second != 0) {
                if (!makeGroup(mp, it, groupSize)) return false;
            }
        }
        return true;
    }

    bool makeGroup(map<int, int>& mp, map<int, int>::iterator it,
                   int groupSize) {
        int num = it->first;
        for (int i = 0; i < groupSize; i++) {
            if (mp[num] > 0) {
                mp[num++]--;
            } else {
                return false;
            }
        }
        return true;
    }
};