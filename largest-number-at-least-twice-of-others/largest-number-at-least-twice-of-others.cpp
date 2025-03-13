class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int maxIndex = 0;
        int maxVal = nums[0], secondMax = INT_MIN;

        // Find the max element and its index
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;  // Update second max
                maxVal = nums[i];    // Update max
                maxIndex = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i]; // Update second max if needed
            }
        }

        // Check the condition
        return (maxVal >= 2 * secondMax) ? maxIndex : -1;
    }
};