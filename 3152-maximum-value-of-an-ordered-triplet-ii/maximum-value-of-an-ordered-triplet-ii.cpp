class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
          int n = nums.size();
        if (n < 3) return 0; // Not enough elements for a valid triplet

        vector<int> bestRight(n, 0); // Store max values from right
        bestRight[n - 1] = nums[n - 1];

        // Precompute bestRight in reverse order
        for (int i = n - 2; i >= 0; i--) {
            bestRight[i] = max(bestRight[i + 1], nums[i]);
        }

        int bestLeft = nums[0];  // Largest value before mid
        long long maxValue = 0;        // Maximum triplet value

        for (int mid = 1; mid < n - 1; mid++) {
            // Get the best right value from precomputed array
            int rightMax = bestRight[mid + 1];

            // Compute triplet value
            long long tripletValue = (long)(bestLeft - nums[mid]) * rightMax;
            maxValue = (long)max(maxValue, tripletValue);

            // Update bestLeft for the next iteration
            bestLeft = max(bestLeft, nums[mid]);
        }

        return maxValue;
        
    }
};