#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;

        stack <string> st;
        while (i < n){
            // skipping any spaces
            while ( i<n && s[i] == ' ') i++;

            string word = "";
            while (i<n && s[i] != ' '){
                word += s[i++];
            }

            // if a word was formed , push it to the stack..
            if (!word.empty()){
                st.push(word);
            }
        }

        string ans = "";
        // best way to Ensure to avoid appending an extra space at the end.
        while (!st.empty()){
            ans += st.top();
            st.pop();

            if (!st.empty()){
                ans += " ";
            }
        }

        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();


/*
string par iterate karta hu... spaces ko ignore karna hai jab bhi aaye...
aur jaise hi ek word ban jaata hai ...usko stack mai push kar do....

then stack se word nikal ke word form karna hai....


*/

#include <string>
using namespace std;

class Solution {
private:
    // Helper function to reverse characters in the string from index i to j
    void reverse(string &s, int i, int j) { 
        while(i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }

public:
    string reverseWords(string &s) {
        int i = 0, j = 0; // i is the read pointer, j is the write pointer
        int l = 0; // Start index of a word
        int len = s.length();
        int wordcount = 0; // To count the number of words processed

        while (true) {
            // Skip spaces to find the start of a word
            while (i <= len - 1 && s[i] == ' ') i++;
            
            // If i reaches the end of the string, break out of the loop
            if (i == len) break;
            
            // If this is not the first word, add a space before the new word
            if (wordcount) s[j++] = ' ';
            
            // Mark the start index of the new word
            l = j;
            
            // Copy characters from the current word to the correct position
            while (i < len && s[i] != ' ') {
                s[j] = s[i];
                i++;
                j++;
            }
            
            // Reverse the current word
            reverse(s, l, j - 1);
            
            // Increment the word count
            wordcount++;
        }

        // Resize the string to remove any trailing characters
        s.resize(j);
        
        // Reverse the entire string to get words in reverse order
        reverse(s, 0, j - 1);
        
        return s;
    }
};




/*

Initialize Pointers and Variables: Use i as a read pointer, j as a write pointer, l to mark the start of a word, and wordcount to keep track of the number of words processed.
Skip Leading Spaces: Move the read pointer i to skip any leading spaces.
Process Each Word:
If a word has been processed (wordcount > 0), add a space before the next word.
Mark the start of the new word with l.
Copy characters of the word from the read pointer i to the write pointer j.
Reverse the characters of the current word using the reverse helper function.
Increment the wordcount.
Resize the String: Adjust the size of the string to remove any trailing characters.
Reverse the Entire String: Finally, reverse the entire string to get the words in the correct reversed order.

*/