class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
          
            // pi is the partition return index of pivot
            int pi = partition(arr, low, high);
    
            // Recursion calls for smaller elements
            // and greater or equals elements
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // Choose the pivot
        int pivot = arr[high];
      
        // Index of smaller element and indicates 
        // the right position of pivot found so far
        int i = low - 1;
    
        // Traverse arr[low..high] and move all smaller
        // elements on left side. Elements from low to 
        // i are smaller after every iteration
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        // Move pivot after smaller elements and
        // return its position
        swap(arr[i + 1], arr[high]);  
        return i + 1;    
        
    }
};
