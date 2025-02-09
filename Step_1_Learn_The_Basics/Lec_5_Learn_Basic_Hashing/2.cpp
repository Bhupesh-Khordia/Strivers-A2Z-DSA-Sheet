class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // O(n) Space Complexity
        
        // unordered_map<int, int> map;
        // for(auto i : arr) {
        //     map[i]++;
        // }
        // for(int i = 0; i < arr.size(); i++) {
        //     arr[i] = map[i+1];
        // }
        // return arr;
        
        
        // O(1) space complexity.
        
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            arr[i]--; // To make 0 based indexing
        }
        
        for(int i =0; i < n; i++){
            if(arr[i] % (n + 1)  < n)
                arr[arr[i] % (n + 1)] += n + 1;
        }
        
        for(int i =0; i < n; i++){
            arr[i] /= n+1;
        }
        
        return arr;
    }
};
