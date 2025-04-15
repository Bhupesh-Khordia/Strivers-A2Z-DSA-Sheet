// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

/*
class Solution {
  private:
    int merge(vector<int> &arr, int l, int mid, int r) {
        vector<int> temp;
        int left = l;
        int right = mid + 1;
        int inversions = 0;
        
        while( left <= mid && right <= r ) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
                // Inversion Found
                inversions += mid - left + 1;
            }
        }
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= r) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
        
        return inversions;
    }
  
    int mergeSort(vector<int> &arr, int l, int r) {
        if(l >= r) return 0;
        
        int mid = l + ((r - l) / 2);
        int left = mergeSort(arr, l, mid);
        int right = mergeSort(arr, mid + 1, r);
        int final = merge(arr, l, mid, r);
        
        return left + right + final;
    }
    
    
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // We will use Merge sort to count inversions
        
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
*/


// https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM


// /*
#include <bits/stdc++.h>
using namespace std;

long long merge(long long* arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<long long> left(n1);
    vector<long long> right(n2);

    for (int i = 0; i < n1; ++i) left[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (n1 - i); // Inversion found
        }
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return inversions;
}

long long mergeSort(long long* arr, int l, int r) {
    if (l >= r) return 0;

    int mid = l + (r - l) / 2;
    long long inv = 0;

    inv += mergeSort(arr, l, mid);
    inv += mergeSort(arr, mid + 1, r);
    inv += merge(arr, l, mid, r);

    return inv;
}

long long getInversions(long long* arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

// */
