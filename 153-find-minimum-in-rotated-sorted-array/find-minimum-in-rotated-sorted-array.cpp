class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the rightmost element, minimum is in right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // Otherwise, minimum is in left half (including mid)
            else {
                high = mid;
            }
        }
        
        return nums[low];  // Low will be at the minimum element
    }
};

