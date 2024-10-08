#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<>> pq;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for (int i: nums) {
            pq.push(i);
        }
        while (pq.size() > k) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};