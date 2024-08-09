#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set <int> zrow;
        unordered_set <int> zcol;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == 0){
                    zrow.insert(i);
                    zcol.insert(j);
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(zrow.find(i) != zrow.end()){
                    matrix[i][j] = 0;
                }
                
                if(zcol.find(j) != zcol.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
row ki set 
col ki set 

first iterartion mai mark position of zeroes..
then second iteration mai modify kara..

*/


//   ---------------

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool flag1 = false, flag2 = false;

        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){  // if column1 contains any zero
                flag1 = true;
            }
        }

        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0){  // if row1 contains any zero
                flag2 = true;
            }
        }

        for(int i=1; i<n; i++){ // next row, next col se start kara 
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){  // agar kahi beech mai bhi zero mil gaya to....
            // bas aap zeroth row or zeroth column ko hi zero banao....ye ek tarah se mark ho gaya yaad karne ka...
            // matlab koi bhi zero ho ...magar hum to zeroth ya zeroth column ko hi zero banaya karenge...
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // now again first row, first col se start kara.../
        // bas ab ye dekha ki matrix[i][j] ko tab zero karenge.. jab aapka us corresponding 
        // cell ke liye zeroth row mai ya zeroth col mai zero pehle se pada ho..
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // bachi hui kasar ko bhi pura kara
        if(flag1 == true){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(flag2 == true){
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }

   
    }
};


// iterating over each loop if v[i][j] == 0 make that
// complete row and complete column equals zero..