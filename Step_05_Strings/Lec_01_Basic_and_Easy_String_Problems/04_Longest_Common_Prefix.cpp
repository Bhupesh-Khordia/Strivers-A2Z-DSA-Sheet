// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 1) return strs[0];
            string str1 = "";
            string str2 = "";
            int commonCnt = 0;
            int finalCnt = INT_MAX;
    
            for(int i = 1; i < strs.size(); i++) {
                str1 = strs[i - 1];
                str2 = strs[i];
                int m = str1.length();
                int n = str2.length();
                commonCnt = 0;
    
                for(int i = 0; i < m && i < n; i++) {
                    if(str1[i] == str2[i]) {
                        commonCnt++;
                    } else {
                        break;
                    }
                }
                finalCnt = min(finalCnt, commonCnt);
            }
    
            return strs[0].substr(0, finalCnt);
        }
    };
    
    
    
    // Trie Solution
    
    /*
    class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;
    
        TrieNode(char data) {
            this -> data = data;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
                childCount = 0;
            }
            isTerminal = false;
        }
    };
    
    class Trie {
    
    public:
    
        TrieNode* root;
    
        // Initialize your data structure here.
        Trie() {
            root = new TrieNode('\0');
        }
    
        // Inserts a word into the trie. 
    
        void insertUtil(TrieNode* root, string& word) {
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }
    
            int index = word[0] - 'a';
            TrieNode* child;
            if(root -> children[index]) {
                child = root -> children[index];
            }
            else {
                child = new TrieNode(word[0]);
                root -> children[index] = child;
                root -> childCount++;
            }
    
            string str = word.substr(1);
            insertUtil(child, str);
        }
        void insert(string& word) {
            insertUtil(root, word);
        }
    
        void lcp(string& str, string& ans) {
            for(int i = 0; i < str.length(); i++) {
                char ch = str[i];
    
                if(root -> childCount == 1) {
                    ans.push_back(ch);
                    root = root -> children[ch-'a'];
                }
                else {
                    break;
                }
    
                if(root -> isTerminal) return;
            }
        }
    };
    
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            Trie* t = new Trie();
    
            for(auto i : strs) {
                if(i == "") return i;
                t->insert(i);
            }
    
            string first = strs[0];
            string ans = "";
    
            t->lcp(first, ans);
    
            return ans;
        }
    };
    */