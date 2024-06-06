#include <cctype>
#include <string>
using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        int front = 0, rear = s.length() - 1;
        while (rear >= front) {
            if (!isalpha(s[rear]) && !isdigit(s[rear])) {
                rear--;
            } else if (!isalpha(s[front]) && !isdigit(s[front])) {
                front++;
            } else if (tolower(s[rear]) == tolower(s[front])) {
                rear--;
                front++;
            } else {
                return false;
            }
        }
        return true;
    }
};