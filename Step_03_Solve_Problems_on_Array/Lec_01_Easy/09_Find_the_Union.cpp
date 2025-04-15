// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        vector<int> ans;
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                if(ans.empty()) {
                    ans.push_back(a[i]);
                    i++;
                } else {
                    if(ans[ans.size() - 1] == a[i]) i++;
                    else {
                        ans.push_back(a[i]);
                        i++;
                    }
                }
            } else {
                if(ans.empty()) {
                    ans.push_back(b[j]);
                    j++;
                } else {
                    if(ans[ans.size() - 1] == b[j]) j++;
                    else {
                        ans.push_back(b[j]);
                        j++;
                    }
                }
            }
        }
        while(i < a.size() ) {
            if(ans.empty()) {
                ans.push_back(a[i]);
                i++;
            } else {
                if(ans[ans.size() - 1] == a[i]) i++;
                else {
                    ans.push_back(a[i]);
                    i++;
                }
            }
        }
        while(j < b.size()) {
            if(ans.empty()) {
                ans.push_back(b[j]);
                j++;
            } else {
                if(ans[ans.size() - 1] == b[j]) j++;
                else {
                    ans.push_back(b[j]);
                    j++;
                }
            }
        }
        return ans;
        
    }
};
