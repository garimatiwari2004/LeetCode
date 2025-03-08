class Solution {
public:
    int characterReplacement(string s, int k) {
          vector<int> freq(26, 0); // Store frequency of each character
    int maxFreq = 0;         // Maximum frequency of any character in the window
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right] - 'A']++;  // Update frequency of current character
        maxFreq = max(maxFreq, freq[s[right] - 'A']); // Track max character frequency

        // Check if window is valid: (window size - maxFreq) should be <= k
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--; // Shrink the window
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};