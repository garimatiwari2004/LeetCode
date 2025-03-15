class Solution {
public:
    bool canRobWithCapability(vector<int>& nums, int k, int capability) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= capability) {
                count++;
                i++;  // Skip the next house since adjacent houses cannot be robbed
            }
            if (count >= k) return true;  // We successfully picked at least k houses
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canRobWithCapability(nums, k, mid)) {
                ans = mid;  // Store the best possible capability
                high = mid - 1;  // Try to minimize further
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
