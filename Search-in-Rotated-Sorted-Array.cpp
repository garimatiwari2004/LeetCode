class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the target is found at mid
            if (nums[mid] == target) return mid;

            // Check which half is sorted
            if (nums[low] <= nums[mid]) { // Left half is sorted
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Search in left half
                } else {
                    low = mid + 1; // Search in right half
                }
            } else { // Right half is sorted
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1; // Search in right half
                } else {
                    high = mid - 1; // Search in left half
                }
            }
        }

        return -1; // Target not found
    }
};
