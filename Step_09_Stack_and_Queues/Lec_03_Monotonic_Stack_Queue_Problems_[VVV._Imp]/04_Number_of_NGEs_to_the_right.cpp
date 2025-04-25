// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

class Solution {
    public:
  
      vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
          stack<int> asc; // Elements will be in ascending order from top to bottom.
          stack<int> temp;  // Remaining elements will be temporarily stored in this stack.
          vector<int> NGE (n, 0);
          
          for(int i = n - 1; i >= 0; i--) {
              while(!asc.empty() && arr[i] >= asc.top()) {
                  temp.push(asc.top()); // Temporarily store in temp in descending order
                  asc.pop();
              }
              // Asc will only contain elements greater than arr[i]
              NGE[i] = asc.size();
              temp.push(arr[i]);
              while(!temp.empty()) {
                  asc.push(temp.top()); // Push again for furter use. (in ascending order)
                  temp.pop();
              }
          }
          
          for(int i = 0; i < queries; i++) {
              indices[i] = NGE[indices[i]];
          }
          return indices;
      }
  };