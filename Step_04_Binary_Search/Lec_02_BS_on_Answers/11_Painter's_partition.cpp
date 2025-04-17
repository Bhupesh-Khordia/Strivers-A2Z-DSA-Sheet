// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557


/*
bool isPossibleSoln(vector<int> &boards, int k, int mid) {
    int n = boards.size();
    int painters = 1;
    int area = 0;
    for(int i = 0; i < n; i++) {
        if(area + boards[i] <= mid) {
            area += boards[i];
        }
        else {
            painters++;
            if(painters > k || boards[i] > mid) {
                return false;
            }
            area = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    for(int i = 0; i < boards.size(); i++) {
        sum += boards[i];
    }
    int e = sum;

    int mid = s + ((e - s) / 2);
    int ans = -1;

    while (s <= e) {
        if(isPossibleSoln(boards, k, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
}
*/




// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// /*
class Solution {
  private:
    bool isPossibleSoln(vector<int> &arr, int k, int mid) {
        int n = arr.size();
        int painters = 1;
        long long area = 0;
        for(int i = 0; i < n; i++) {
            if(area + arr[i] <= mid) {
                area += arr[i];
            }
            else {
                painters++;
                if(painters > k || arr[i] > mid) {
                    return false;
                }
                area = arr[i];
            }
        }
        return true;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        int s = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        int e = sum;
    
        int mid = s + ((e - s) / 2);
        int ans = -1;
    
        while (s <= e) {
            if(isPossibleSoln(arr, k, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
            mid = s + ((e - s) / 2);
        }
        return ans;
    }
};
// */