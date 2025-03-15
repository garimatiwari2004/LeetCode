class Solution {
public:
    bool canRob(vector<int>& nums, int k, int C) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= C) {
                count++;
                i++;  // Skip adjacent house
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canRob(nums, k, mid))
                high = mid;  // Try lowering the capability
            else
                low = mid + 1;  // Increase capability
        }

        return low;  // The smallest valid capability
    }
};

