# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/java-switch-case-statement3529/1


# include <cmath>

class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        double pi = M_PI; 
        switch (choice) {
            case 1 :
                return pi * arr[0] * arr[0];
            case 2 :
                return arr[0] * arr[1];
        }
    }
};