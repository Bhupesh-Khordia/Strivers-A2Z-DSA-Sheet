class Solution {
  private:
    void rev(vector<int> &arr, int &i, int &j) {
        if(j <= i) return;
        swap(arr[i++], arr[j--]);
        rev(arr, i, j);
    }
  public:
    void reverseArray(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;
        rev(arr, i, j);
    }
};
