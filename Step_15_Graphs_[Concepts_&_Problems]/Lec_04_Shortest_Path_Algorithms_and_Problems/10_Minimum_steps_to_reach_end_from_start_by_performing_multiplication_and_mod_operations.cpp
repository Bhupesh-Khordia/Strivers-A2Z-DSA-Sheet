#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        queue<int> q;
        q.push(start);
        
        vector<bool> visited(100000, false);
        visited[start] = true;
        int steps = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                int frontNode = q.front(); q.pop();
                
                if(frontNode == end) return steps;
                
                for(int i = 0; i < n; i++) {
                    long long nbr = (frontNode * arr[i]) % 100000 ;
                    
                    if(!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};
