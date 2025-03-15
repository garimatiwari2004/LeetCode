class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result(2,-1);
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }else low=mid+1;
        }
         if (low < nums.size() && nums[low] == target) 
            result[0] = low;
        else  return result; 
        high=nums.size()-1;
         while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        
        result[1] = high;
        return result;
        
    }
};