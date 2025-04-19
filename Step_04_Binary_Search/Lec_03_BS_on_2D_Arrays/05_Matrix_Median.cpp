// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
    public:
      int median(vector<vector<int>> &mat) {
          int row=mat.size(),col=mat[0].size();
          int mn=INT_MAX,mx=INT_MIN;
          for(int i=0;i<row;i++)
          {
              mn=min(mn,mat[i][0]);
              mx=max(mx,mat[i][col-1]);
          }
          
          int l=mn,h=mx,mid;
          int med=(row*col+1)/2;  // That much elements will be less than or equal to the median in final sorted array.
          while(l<h)
          {
              mid=l+(h-l)/2;
              int idx=0; // will store elements less than or equal to mid
              for(int i=0;i<row;i++)
              {
                  idx+=upper_bound(mat[i].begin(),mat[i].begin()+col,mid)-mat[i].begin();
              }
              
              if(idx < med) {
                  l=mid+1;
              }
              else
              {
                  h = mid;
              }
          }
          return l;
      }
  };