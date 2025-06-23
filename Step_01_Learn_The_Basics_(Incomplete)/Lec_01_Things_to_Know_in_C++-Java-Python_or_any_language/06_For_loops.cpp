# include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156

#include<bits/stdc++.h>
using namespace std;

int main()
{
        int  n;
        cin >> n;

        int prev1 = 0;
        int prev2 = 1;
        int curr;
        if(n < 2) {
                cout << n;
                return 0;
        }
        for(int i = 0; i <= n-2; i++) {
                curr = prev1 + prev2;
                prev1 = prev2;
                prev2 = curr;
        }
        cout << curr;
        return 0;
}