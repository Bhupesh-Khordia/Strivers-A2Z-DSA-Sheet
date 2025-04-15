class Solution {
  private:
    void solve(vector<int>& arr, int index) {
        int n = arr.size();
        if(index == n) return;
        
        bool swapped = false;
        for(int i = 0; i < n - index - 1; i++) {
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                swapped = true;
            } 
            
        }
        
        if(!swapped) return;
        solve(arr, index + 1);
    }
    
  public:
    // Function to sort the array using bubble sort algorithm.
    
    
    // void bubbleSort(vector<int>& arr) {
    //     int n = arr.size();
    //     bool swapped;
      
    //     for (int i = 0; i < n - 1; i++) {
    //         swapped = false;
    //         for (int j = 0; j < n - i - 1; j++) {
    //             if (arr[j] > arr[j + 1]) {
    //                 swap(arr[j], arr[j + 1]);
    //                 swapped = true;
    //             }
    //         }
          
    //         // If no two elements were swapped, then break
    //         if (!swapped)
    //             break;
    //     }
    // }
    
    
    // Recursive Bubble sort
    void bubbleSort(vector<int>& arr) {
        solve(arr, 0);
    }
    
};
