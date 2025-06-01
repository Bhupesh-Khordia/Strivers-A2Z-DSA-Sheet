#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule/description/

// In Course Schedule - II, i used DFS so here i m using BFS.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create a graph with edges - prerequisites of course A -> A

        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // Kahn's Algorithm 

        vector<int> indegree(numCourses, 0);
        for(auto i : prerequisites) {
            indegree[i[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            int front = q.front(); q.pop();
            
            ans.push_back(front);
            
            for(auto nbr : adjList[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        if(ans.size() == numCourses) return true;
        return false; // Cycle present
    }
};