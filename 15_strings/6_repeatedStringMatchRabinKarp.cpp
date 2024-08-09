class Solution {
private:
    int BASE = 1000000; // Large prime number to minimize hash collisions
public:
    int repeatedStringMatch(string A, string B) {
        if (A == B) return 1; // If A and B are identical, return 1
        int count = 1;
        string source = A;
        while (source.size() < B.size()) { // Build source until its size >= B's size
            count++;
            source += A;
        }
        if (source == B) return count; // Check if current source equals B
        if (Rabin_Karp(source, B) != -1) return count; // Check if B is a substring of source
        if (Rabin_Karp(source + A, B) != -1) return count + 1; // Append A once more and check again
        return -1; // B is not a substring even after appending A
    }
    
    int Rabin_Karp(string source, string target) {
        if (source == "" || target == "") return -1;
        int m = target.size();
        int power = 1;
        for (int i = 0; i < m; i++) {
            power = (power * 31) % BASE; // Calculate 31^m % BASE
        }
        int targetCode = 0;
        for (int i = 0; i < m; i++) {
            targetCode = (targetCode * 31 + target[i]) % BASE; // Hash code for target
        }
        int hashCode = 0;
        for (int i = 0; i < source.size(); i++) {
            hashCode = (hashCode * 31 + source[i]) % BASE; // Rolling hash for source
            if (i < m - 1) continue; // Wait until hashCode has at least m characters
            if (i >= m) {
                hashCode = (hashCode - source[i - m] * power) % BASE; // Remove the character that slid out
            }
            if (hashCode < 0) hashCode += BASE; // Ensure hashCode is non-negative
            if (hashCode == targetCode) { // Potential match
                if (source.substr(i - m + 1, m) == target) // Verify actual substring
                    return i - m + 1;
            }
        }
        return -1; // No match found
    }
};
