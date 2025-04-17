// https://www.naukri.com/code360/problems/allocate-books_1090540?leftPanelTabValue=PROBLEM

/*
bool isPossible(vector<int> &arr, int m, int mid) {
    int studentCnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCnt ++;
            if(arr[i] > mid || studentCnt > m) return false;
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(s <= e) {
        int mid = s + (e - s) / 2;

        if(isPossible(arr, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
*/



// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// /*
class Solution {
    private :
       bool isPossible(vector<int> &arr, int m, int mid) {
          int studentCnt = 1;
          int pageSum = 0;
          for(int i = 0; i < arr.size(); i++) {
              if(pageSum + arr[i] <= mid) {
                  pageSum += arr[i];
              } else {
                  studentCnt ++;
                  if(arr[i] > mid || studentCnt > m) return false;
                  pageSum = arr[i];
              }
          }
          return true;
      }
    public:
      int findPages(vector<int> &arr, int k) {
          int n = arr.size();
          if(k > n) return -1;
          int s = *max_element(arr.begin(), arr.end());
          int e = accumulate(arr.begin(), arr.end(), 0);
          int ans = -1;
          while(s <= e) {
              int mid = s + (e - s) / 2;
      
              if(isPossible(arr, k, mid)) {
                  ans = mid;
                  e = mid - 1;
              } else {
                  s = mid + 1;
              }
          }
          return ans;
      }
  };

// */