#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/alien-dictionary/description/
 
// No money to buy leetcode premium, so I am solving this problem on GeeksforGeeks. :(


// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;

        // Step 1: Initialize indegree for all characters
        for (auto& word : words) {
            for (char ch : word) {
                if (!indegree.count(ch)) {
                    indegree[ch] = 0;
                }
            }
        }

        // Step 2: Build graph
        // Graph such that edge a - b => a is lexographically greater than b
        for (int i = 1; i < words.size(); i++) {
            string prev = words[i - 1];
            string curr = words[i];
            
            int idx = 0;
            while (idx < prev.length() && idx < curr.length() && prev[idx] == curr[idx]) {
                idx++;
            }
            
            // Edge Case
            if(idx == min(prev.length(), curr.length()) && prev.length() > curr.length()) return "";

            if (idx < prev.length() && idx < curr.length()) {
                char from = prev[idx], to = curr[idx];
                adjList[from].push_back(to);
                indegree[to]++;
            }
        }

        // Step 3: Kahn's algorithm (BFS topological sort)
        queue<char> q;
        for (auto& entry : indegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }

        string topo = "";
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            topo += curr;

            for (char neighbor : adjList[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo.length() == indegree.size() ? topo : "";
    }
};
