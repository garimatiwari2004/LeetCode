class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid;
        if(nums[0]>target) return 0;
        if(nums[high]<target) return high+1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};