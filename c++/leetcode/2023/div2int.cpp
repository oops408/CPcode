//using knuth morris pratt algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) 
            return 0;
        //In the KMP algorithm, the pi vector (short for prefix function) is used to store the length of the longest proper prefix of the pattern (needle) that is also a suffix of a substring of the pattern.

//The purpose of the pi vector is to avoid unnecessary comparisons when searching for the pattern in the text (haystack). 
//When a mismatch occurs between the pattern and the text, the pi vector tells us the length of the longest prefix of the pattern that matches a suffix of the pattern up to the mismatch position. 
//We can then shift the pattern to the right by this length and continue the search from there instead of starting over from the beginning of the pattern.

//For example, consider the pattern ABCDABD. If we have matched the first four characters ABCD with the text but the next character in the text is X, which does not match the next character A in the pattern, we can shift the pattern to the right by pi[3] = 0 characters and start comparing the next character in the text with the first character A in the shifted pattern (DABD). 
//Without the pi vector, we would have to start over from the beginning of the pattern (ABCDABD).
        vector<int> pi(m);
        pi[0] = 0;
        int j = 0;
        for (int i = 1; i < m; i++) {
            //while (j > 0 && needle[j] != needle[i]) { j = pi[j - 1]; }: This statement is used to update the value of j (the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern) when a mismatch is found between the characters of the pattern at positions j and i. 
            //The idea here is to use the pi values computed so far to find the longest proper prefix of the pattern that is also a suffix of a substring of the pattern that matches the characters of the pattern up to position i. 
            //We do this by using the value of pi[j-1], which represents the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position j-1. 
            //We update j to this value and continue the loop until we find a proper prefix that matches a suffix of the pattern up to position i or we reach the beginning of the pattern (j = 0).
            while (j > 0 && needle[j] != needle[i]) {
                j = pi[j - 1];
            }
            //if (needle[j] == needle[i]) { j++; }: This statement is used to update the value of j when a match is found between the characters of the pattern at positions j and i. 
            //If the characters match, we increment j by 1, indicating that we have found a new character that matches the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position i.
            if (needle[j] == needle[i]) {
                j++;
            }
            //pi[i] = j;: This statement is used to store the value of j in the pi vector at position i. This represents the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position i. 
            //By computing the pi vector in this way, we can use it in the KMP algorithm to avoid unnecessary comparisons when searching for the pattern in the text.
            pi[i] = j;
        }
        j = 0;
        for (int i = 0; i < n; i++) {
            //while (j > 0 && needle[j] != haystack[i]) { j = pi[j - 1]; }: This statement is used to update the value of j (the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern) when a mismatch is found between the characters of the pattern and the text. 
            //This works similarly to the prefix function algorithm used to compute the pi vector, as explained in my previous answer. 
            //We use the pi values computed so far to find the longest proper prefix of the pattern that is also a suffix of a substring of the pattern that matches the characters of the text up to position i. 
            //If a mismatch is found between the characters of the pattern and the text at position j and i, we update j to the pi value at position j-1 and continue the loop until we find a proper prefix that matches a suffix of the pattern up to position i or we reach the beginning of the pattern (j = 0).

            while (j > 0 && needle[j] != haystack[i]) {
                j = pi[j - 1];
            }
            //if (needle[j] == haystack[i]) { j++; }: This statement is used to update the value of j when a match is found between the characters of the pattern and the text. 
            //If the characters match, we increment j by 1, indicating that we have found a new character that matches the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position i.
            if (needle[j] == haystack[i]) {
                j++;
            }
            //if (j == m) { return i - m + 1; }: This statement is used to check if we have found a complete match of the pattern in the text. 
            //If j is equal to the length of the pattern m, then we have found a complete match, and we return the starting index of the match in the text (i - m + 1).
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};
