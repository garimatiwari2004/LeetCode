class Solution {
public:


// Function to count subarrays with at most k odd numbers
int atMostK(vector<int>& nums, int k) {
    if (k < 0) return 0; // Edge case: If k is negative, no subarray is possible.

    int left = 0, count = 0, oddCount = 0;

    for (int right = 0; right < nums.size(); right++) {
        // If the current number is odd, increase the odd count
        if (nums[right] % 2 == 1) {
            oddCount++;  
        }

        // If more than k odd numbers, shrink the window from the left
        while (oddCount > k) {
            if (nums[left] % 2 == 1) {
                oddCount--;  // Reduce the odd count
            }
            left++;  // Move left pointer
        }

        // Count all valid subarrays ending at 'right'
        count += (right - left + 1);
    }
    return count;
}

// Function to count exactly k odd numbers in a subarray
int numberOfSubarrays(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

// Driver code


};