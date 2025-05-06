// https://leetcode.com/problems/lemonade-change/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int fiveD = 0;
            int tenD = 0;
            // int twentyD = 0;
            // int balance = 0;
            for(int i = 0; i < bills.size(); i++) {
                if(bills[i] == 5) {
                    fiveD++;
                    // balance+=5;
                } else if(bills[i] == 10) {
                    if(fiveD >= 1) {
                        fiveD--;
                        tenD++;
                        // balance+=5
                    } else return false;
                } else {
                    if(fiveD >= 1 && tenD >= 1) {
                        fiveD--;
                        tenD--;
                        // twentyD++;
                        // balance+=5;
                    } else if (fiveD >= 3) {
                        fiveD -= 3;
                        // twentyD++;
                    } else return false;
                }
            }
            return true;
        }
    };