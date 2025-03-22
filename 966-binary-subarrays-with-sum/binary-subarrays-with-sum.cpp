class Solution {
public:
int atMostSum(vector<int>& nums, int goal) {
    if (goal < 0) return 0; // No valid subarray possible
    int left = 0, sum = 0, count = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum > goal) { // Shrink window if sum exceeds goal
            sum -= nums[left];
            left++;
        }
                count += (right - left + 1); // Count subarrays ending at 'right'
    }
    
    return count;
}

    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return atMostSum(nums, goal) - atMostSum(nums, goal - 1);
        
    }
};