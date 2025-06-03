# include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/number-of-islands-ii/description/
// --------------------------------------------------------------------------------------------------------------------------------

// No money to buy leetcode premium. :(



// ----------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/number-of-islands/0
// ----------------------------------------------------------------------------------------------------------------------------------

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int parentFind(int node) {
        if (parent[node] == node) return node;
        return parent[node] = parentFind(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
  private:
    int convert(int x, int y, int m) {
        return y + x * m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        /*
        We convert 2d plane to single number
        
        01 02 03 04
        05 06 07 08
        09 10 11 12
        13 14 15 16
        */
        
        int maxSize = n * m;
        DisjointSet ds(maxSize);
        
        int cnt = 0;
        vector<vector<bool>> grid(n, vector<bool> (m, false));
        vector<int> ans;
        
        for(int i = 0; i < operators.size(); i++) {
            int x = operators[i][0];
            int y = operators[i][1];
            
            if(grid[x][y]) {
                ans.push_back(cnt);
                continue;
            }
            
            grid[x][y] = 1;
            cnt++; // Assume new island formed
            
            vector<int> dirx = {0, 0, 1, -1}, diry = {1, -1, 0, 0};
            
            for(int i = 0; i < 4; i++) {
                int adjX = x + dirx[i];
                int adjY = y + diry[i];
                
                if(adjX < 0 || adjX >= n || adjY < 0 || adjY >= m || !grid[adjX][adjY]) continue;
                
                int curr = convert(x, y, m);
                int nbr = convert(adjX, adjY, m);
                
                int parCurr = ds.parentFind(curr);
                int parnbr = ds.parentFind(nbr);
                
                if(parCurr != parnbr) {
                    cnt--; // No new island
                    ds.unionByRank(curr, nbr); // Merge them
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};





// --------------------------------------------------------------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/number-of-islands-ii_1266048
// --------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int parentFind(int node) {
        if (parent[node] == node) return node;
        return parent[node] = parentFind(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int convert(int x, int y, int m) {
	return y + x * m;
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	/*
	We convert 2d plane to single number
	
	01 02 03 04
	05 06 07 08
	09 10 11 12
	13 14 15 16
	*/
	
	int maxSize = n * m;
	DisjointSet ds(maxSize);
	
	int cnt = 0;
	vector<vector<bool>> grid(n, vector<bool> (m, false));
	vector<int> ans;
	
	for(int i = 0; i < q.size(); i++) {
		int x = q[i][0];
		int y = q[i][1];
		
		if(grid[x][y]) {
			ans.push_back(cnt);
			continue;
		}
		
		grid[x][y] = 1;
		cnt++; // Assume new island formed
		
		vector<int> dirx = {0, 0, 1, -1}, diry = {1, -1, 0, 0};
		
		for(int i = 0; i < 4; i++) {
			int adjX = x + dirx[i];
			int adjY = y + diry[i];
			
			if(adjX < 0 || adjX >= n || adjY < 0 || adjY >= m || !grid[adjX][adjY]) continue;
			
			int curr = convert(x, y, m);
			int nbr = convert(adjX, adjY, m);
			
			int parCurr = ds.parentFind(curr);
			int parnbr = ds.parentFind(nbr);
			
			if(parCurr != parnbr) {
				cnt--; // No new island
				ds.unionByRank(curr, nbr); // Merge them
			}
		}
		
		ans.push_back(cnt);
	}
	
	return ans;
}