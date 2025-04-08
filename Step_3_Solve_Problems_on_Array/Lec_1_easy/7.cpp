
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    
    bool binarySearch(vector<int>& arr, int k, int l, int r) {
        if (l > r) return false;

        int mid = l + (r - l) / 2;

        if (arr[mid] == k) return true;
        else if (arr[mid] > k)
            return binarySearch(arr, k, l, mid - 1);
        else
            return binarySearch(arr, k, mid + 1, r);
    }
    
    bool searchInSorted(vector<int>& arr, int k) {
        
        return binarySearch(arr, k, 0, arr.size() - 1);
    }
};

