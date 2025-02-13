class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int n  = arr.size();
        for(int i = 0; i < n; i++) {
            int minIdx = i;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[minIdx]) minIdx = j;
            }
            swap(arr[minIdx], arr[i]);
        }
    }
};
