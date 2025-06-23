# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/data-type-1666706751/1



// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dataTypeSize(string str) {
        if(str == "Character") return 1;
        if(str == "Integer") return 4;
        if(str == "Long") return 8;
        if(str == "Float") return 4;
        if(str == "Double") return 8;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends