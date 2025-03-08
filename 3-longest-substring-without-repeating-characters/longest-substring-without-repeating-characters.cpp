class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> charSet; // Store unique characters in the window
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        // If duplicate character found, shrink window
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }

        // Expand window
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
        
    }
};