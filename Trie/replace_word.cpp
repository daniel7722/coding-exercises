#include <vector>
#include <string>

using namespace std;

class Node {
public:
    char c;
    vector<Node*> next;
    bool end;

    Node(char c) : c(c), end(false) {
        next = vector<Node*>(26);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* trie = new Node('0');
        for (string s: dictionary) {
            insert(trie, s);
        }

        Node* traverse;
        string ans;
        for (int i = 0; i < sentence.length(); i++) {
            traverse = trie;
            if (traverse->next[sentence[i]-'a']) {
                bool end = false;
                while (i < sentence.length() && !isspace(sentence[i]) && traverse->next[sentence[i]-'a']) {
                    traverse = traverse->next[sentence[i]-'a'];
                    ans.push_back(sentence[i]);
                    i++;
                    if (traverse->end) {
                        while (i < sentence.length() && !isspace(sentence[i])) {
                            i++;
                        }
                        ans.push_back(' ');
                        end = true;
                        break;
                    }
                }
                if (!end) {
                    while (i < sentence.length() && !isspace(sentence[i])) {
                        ans.push_back(sentence[i]);
                        i++;
                    }
                    ans.push_back(' ');
                }
            } else {
                while (i < sentence.length() && !isspace(sentence[i])) {
                    ans.push_back(sentence[i]);
                    i++;
                }
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans;
    }

    void insert (Node* trie, string s) {
        Node* traverse = trie;
        for (char c: s) {
            if (!traverse->next[c-'a']) {
                traverse->next[c-'a'] = new Node(c);
            }
            traverse = traverse->next[c-'a'];
        }
        traverse->end = true;
    }
};