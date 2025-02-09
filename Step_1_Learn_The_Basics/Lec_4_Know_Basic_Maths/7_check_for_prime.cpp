class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // TLE
        
        // int ans = 0;
        // int n = arr.size();
        // int index = 0;
        // while(index <= n-1) {
        //     if(index + arr[index] >= n - 1) {
        //         ans++;
        //         break;
        //     }
        //     index += arr[index];
        //     int temp = index;
        //     while(arr[index] == 0) index--;
        //     if(index == temp) return -1;
        //     ans++;
        // }
        // return ans;
        
        
        int n = arr.size();
        if (n == 1) return 0;

        int jumps = 0, farthest = 0, end = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);

            if (i == end) {  // Time to jump
                jumps++;
                end = farthest;
                if (end >= n - 1) return jumps;
            }
        }

        return -1;
    }
};
