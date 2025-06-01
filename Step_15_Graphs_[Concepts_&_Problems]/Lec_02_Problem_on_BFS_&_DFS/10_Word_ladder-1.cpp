#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder/description/

// T.C. - N x word.length * 26 * (log for set)
// N is wordList.size()
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q; // String, steps
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end()); // For fast lookups

        st.erase(beginWord);  // To mark as visited, we just erase it. Because no point in keeping it and finding another longer path to it.

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;

            for(int i = 0;i<word.size();i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        // it exists in the set
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};




// Very Simple to understand but not very optimal

/*
class Solution {
private:
    bool oneCharDiff(string s1, string s2) {
        int diff = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
                if(diff > 1) return false;
            }
        }

        return diff == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> words (wordList.begin(), wordList.end());
        if(find(words.begin(), words.end(), endWord) == words.end()) return 0;

        words.push_back(beginWord);

        unordered_map<string, unordered_set<string>> graph;

        // Graph with edges between words that differ by one char only.

        for(int i = 0; i < words.size(); i++) {
            string s1 = words[i];

            for(int j = i + 1; j < words.size(); j++) {
                string s2 = words[j];

                if(oneCharDiff(s1, s2)) {
                    graph[s1].insert(s2);
                    graph[s2].insert(s1);
                }
            }
        }

        // BFS from beginWord

        queue<string> q;
        unordered_map<string, bool> visited;
        for(auto it: graph) {
            visited[it.first] = false;
        }

        q.push(beginWord);
        visited[beginWord] = true;
        int level = 1;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                string front = q.front(); q.pop();

                if(front == endWord) return level;

                for(auto nbr: graph[front]) {
                    if(!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }

            level++;
        }

        return 0;
    }
};
*/