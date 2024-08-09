#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;

        if (n == 1) {
            v.push_back({1});
            return v;
        } 
        if (n == 2) {
            v.push_back({1});
            v.push_back({1, 1});
            return v;
        }

        // General case -> threshold
        v.push_back({1});   // First row
        v.push_back({1, 1}); // Second row


        // ab yaha jab mera vector of vector wala v hi capable hai  2d index ki help se 
        // kind of prev aur curr vector ko trace karne mai to mai phir nayi 1d vector kyu banau....

        for (int i = 3; i <= n; i++) {
            vector<int> curr(i, 1); // Initialize current row with 1's

            for (int j = 1; j <= i - 2; j++) {
                curr[j] = v[i - 2][j - 1] + v[i - 2][j];
            }

            // Push current row into the vector
            v.push_back(curr);
        }

        return v;
    }
};


---- good 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // 2d vector
        vector <int> prevRow;   

        for (int i=0; i<numRows; i++){  // ha prevRow suruat mai ekdum khali hoga... but loop hi aisa chalega ki wo fill ho jaega....
            vector <int> currentRow(i+1, 1);
            
            // zero aur 1 numrow to aise hi 1 vector waala push_back ho jaega...usme condition check nahi hogi....
            
            for (int j=1; j<i; j++){    // 0th aur last index waala to 1 hi rehna hai waise bhi...
                currentRow[j] = prevRow[j-1] + prevRow[j];
            }

            result.push_back(currentRow);
            prevRow = currentRow;
        }
        return result;
    }
};


-----

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i=0; i<numRows; i++){
            vector <int> row(i+1, 1);
            for (int j=1; j<i; j++){
                row[j] = result[i-1][j] + result[i-1][j-1];
            }
            result.push_back(row);
        }
        return result;
    }
};



---------

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // recursion -> base case kaam fn call
        if (numRows == 1) return {{1}};


        vector<vector<int>> prevRows = generate(numRows-1);     // fn call pehle likh diya taaki reverse mai aata huye phir kaam ho...

        vector <int> newRow(numRows, 1);    // sabko hi 1 se initialise kiya..but now fill karte time index 1 se start karenge and end se ek kam tak jayenge...
        
        for (int i=1; i<numRows -1; i++){
            newRow[i] = prevRows.back()[i-1] + prevRows.back()[i];
        }

        prevRows.push_back(newRow);
        return prevRows;
    }
};