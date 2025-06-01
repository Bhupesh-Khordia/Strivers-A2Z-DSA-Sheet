#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
private:
    // visited states: 0 = unvisited, 1 = visiting, 2 = visited
    bool dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &ans) {
        visited[node] = 1;

        for(auto nbr : adjList[node]) {
            if(visited[nbr] == 0) {
                if(dfs(nbr, adjList, visited, ans)) return true;
            } else if (visited[nbr] == 1) {
                // dfs function has been called for this node and it is visited
                // Cycle
                return true;
            }
        }
        ans.push_back(node);
        visited[node] = 2; // Fully Visited
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create a graph with edges - prerequisites of course A -> A

        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // Return its topological sort
        vector<int> visited(numCourses, false);
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(dfs(i, adjList, visited, ans)) return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};