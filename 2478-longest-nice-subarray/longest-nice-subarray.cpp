class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
 int left = 0, bitmask = 0, max_length = 0;

    for (int right = 0; right < nums.size(); right++) {
        while ((bitmask & nums[right]) != 0) {
            bitmask ^= nums[left];  // Remove leftmost element from the window
            left++;
        }
        bitmask |= nums[right];  // Add current element to the window
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
        
    }
};