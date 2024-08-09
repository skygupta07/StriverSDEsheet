#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, vector<vector<int>>& dp, int prevIdx, int currIdx) {
        int n = nums.size();
        // base case
        if (currIdx == n) return 0;
        // base ke just baad dp help
        if (dp[prevIdx + 1][currIdx] != -1) return dp[prevIdx + 1][currIdx];

        // notTake ki call 
        int notTake = 0 + f(nums, dp, prevIdx, currIdx + 1);

        // condition check karke take ki call
        int take = 0;
        if (prevIdx == -1 || nums[currIdx] > nums[prevIdx]) {
            take = 1 + f(nums, dp, currIdx, currIdx + 1);
        }

        return dp[prevIdx + 1][currIdx] = max(take, notTake);  
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // 2d dp -> since both prevIdx and currIdx varies....
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return f(nums, dp, -1, 0);
    }
};

/*
recursive solution take aur not take wala tle dega... then us par aap dp laga dena...
*/
