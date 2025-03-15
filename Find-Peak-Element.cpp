class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=nums.size()-1;
        int mid;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        while(low<high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]<nums[mid+1]) low=mid+1;
            else high=mid;
        }
        return high;
        
    }
};