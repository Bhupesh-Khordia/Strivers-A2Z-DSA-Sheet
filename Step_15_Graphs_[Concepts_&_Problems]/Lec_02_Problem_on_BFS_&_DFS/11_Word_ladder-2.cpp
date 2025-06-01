#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder-ii/description/

// ----------------------------------------------------------------------------------
// This approach is not recommended for interviews. See Approach - 2
// ----------------------------------------------------------------------------------
class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);

        // step 1
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            if (word == endWord)
                break;

            for (int i = 0; i < beginWord.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i] = original;
            }
        }

        // step 2
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};



// ----------------------------------------------------------------------------------
// Good enough approach for interview & GFG, but gives MLE on leetcode.
// ----------------------------------------------------------------------------------

/*
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q; // String, steps
        q.push({beginWord});

        unordered_set<string> st(wordList.begin(), wordList.end()); // For fast lookups

        st.erase(beginWord);  // To mark as visited, we just erase it. Because no point in keeping it and finding another longer path to it.
        bool found = false;
        vector<vector<string>> ans;
        unordered_set<string> levelVis;

        while(!q.empty() && !found) {
            int size = q.size();
            levelVis.clear();

            for(int x = 0; x < size; x++) {
                vector<string> output = q.front();
                string word = output[output.size() - 1];
                q.pop();
                if(word == endWord) {
                    ans.push_back(output);
                    found = true;
                }

                for(int i = 0;i<word.size();i++) {
                    char original = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(st.find(word) != st.end()) {
                            // it exists in the set

                            // Instead of directly erasing it, erase after this level's processing
                            levelVis.insert(word);
                            output.push_back(word);
                            q.push(output);
                            output.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }

            for(auto word : levelVis) st.erase(word);
        }
        return ans;
    }
};
*/





// ----------------------------------------------------------------------------------
// Simple to understand but not very optimal (MLE)
// ----------------------------------------------------------------------------------

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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> words (wordList.begin(), wordList.end());
        if(find(words.begin(), words.end(), endWord) == words.end()) return {};

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

        queue<pair<string, vector<string>>> q;
        vector<vector<string>> ans;
        unordered_map<string, bool> visited;
        for(auto it: graph) {
            visited[it.first] = false;
        }

        q.push({beginWord, {beginWord}});
        visited[beginWord] = true;

        bool found = false;

        while(!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            for(int i = 0; i < size; i++) {
                pair<string, vector<string>> front = q.front(); q.pop();
                string str = front.first;
                vector<string> output = front.second;

                if(str == endWord)  {
                    ans.push_back(output);
                    found = true;
                }

                for (auto nbr : graph[str]) {
                    if (!visited[nbr]) {
                        output.push_back(nbr);
                        q.push({nbr, output});
                        output.pop_back();
                        levelVisited.insert(nbr);
                    }
                }
            }
            for (auto word : levelVisited) visited[word] = true;
        }

        return ans;
    }
};
*/