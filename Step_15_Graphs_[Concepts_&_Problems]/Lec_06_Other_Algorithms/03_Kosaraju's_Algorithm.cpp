# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution {
  private:
    void dfsTopo(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    	visited[node] = true;
    
    	for(auto nbr : adj[node]) {
    		if(!visited[nbr]) {
    			dfsTopo(nbr, adj, visited, st);
    		}
    	}
    
    	st.push(node);
    }
    
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    	visited[node] = true;
    
    	for(auto nbr : adj[node]) {
    		if(!visited[nbr]) {
    			dfs(nbr, adj, visited);
    		}
    	}
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
    	// Kosaraju's Algorithm.
    	
    	int v = adj.size();
    
    	// Step - 1
    	// Get Topological sort.
    
    	stack<int> st;
    	vector<bool> visited(v, false);
    
    	for(int i = 0; i < v; i++) {
    		if(!visited[i]) {
    			dfsTopo(i, adj, visited, st);
    		}
    	}
    	
    	// Step - 2
    	// Transpose the graph.
    
    	vector<vector<int>> transposedGraph (v);
    	for(int x = 0; x < v; x++) {
    	    for(auto y : adj[x]) {
    	        // Edge between x -> y
    		    transposedGraph[y].push_back(x);
    	    }
    	}
    	
    	// Reset the visited array to false for DFS on the transposed graph.
        fill(visited.begin(), visited.end(), false);
        
        
    	// Step - 3
    	// Do dfs in order of topological sort.
    
    	int cnt = 0;   // Number of Strongly Connected Components.
    	while(!st.empty()) {
    		int top = st.top();
    		st.pop();
    
    		if(!visited[top]) {
    			dfs(top, transposedGraph, visited);   
    			
    			// If we want components, then pass an array in DFS and store dfs in that, that will be a SCC.
    
    			cnt++;
    		}
    	}
    
    	return cnt;
    }
};