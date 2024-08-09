#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        sort(v.begin(),v.end());    // sorting the string lexicographically...
        int n = v.size();
        string first = v[0];
        string last = v[n-1];

        // agar equal elements sach mai honge to pehle aur last elements se hi pta lag jaega...
        for (int i=0; i<min(first.size(), last.size()); i++){
            if (first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};