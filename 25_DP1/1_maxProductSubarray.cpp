class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = 1;
        int maxProduct = 1;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                swap(maxProduct, minProduct);
            }
            maxProduct = max(maxProduct*nums[i], nums[i]);
            minProduct = min(minProduct*nums[i], nums[i]);
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};


---------

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int pref = 1;
        int suff = 1;
        int ans = INT_MIN;
        int n = arr.size();

        for (int i=0; i<n; i++){
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            pref = pref * arr[i];
            suff = suff * arr[n-i-1];

            ans = max(ans, max(pref, suff));
        }
        return ans;
    }
};


/*
// prefix product nikala ... suffix product nikala ...un dono mai se jo bhi max hoga wahi answer hoga...
*/