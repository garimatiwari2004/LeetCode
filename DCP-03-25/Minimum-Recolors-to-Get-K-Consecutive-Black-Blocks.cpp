class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int n = blocks.length();
        int left = 0; // Left pointer of the window
        int whiteCount = 0; // Count of 'W's in the current window
        int minOperations = INT_MAX; // Minimum number of 'W's in any window

        // Iterate through the string using the right pointer
        for (int right = 0; right < n; right++) {
            // If the current character is 'W', increment the count
            if (blocks[right] == 'W') {
                whiteCount++;
            }

            // When the window size reaches k, update the minimum operations
            if (right - left + 1 == k) {
                minOperations = std::min(minOperations, whiteCount);

                // Move the left pointer forward
                if (blocks[left] == 'W') {
                    whiteCount--;
                }
                left++;
            }
        }

        return minOperations;
    }
};