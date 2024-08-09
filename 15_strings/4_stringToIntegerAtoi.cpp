#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    // Minimum value for a signed 32-bit integer
    const int miniMod = -2147483648; // -2^31

    // Maximum value for a signed 32-bit integer
    const int maxiMod = 2147483647; // 2^31 - 1

    int myAtoi(string s) {
        // Skipping leading whitespaces
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ') i++;

        // Checking for sign
        bool negative = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            negative = (s[i] == '-');
            i++;
        }

        // Forming the number with sign handling
        long long x = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + (s[i] - '0');
            if (negative) {
                if (-x < miniMod) return miniMod; // Check for underflow
            } else {
                if (x > maxiMod) return maxiMod; // Check for overflow
            }
            i++;
        }

        if (negative) x = -x;

        return static_cast<int>(x); // Ensure the return value is of type int
    }
};
