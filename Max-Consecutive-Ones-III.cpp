class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int maxlength=0;
        int count=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                count++;
            }
            while(count>k){
                if(nums[left]==0){
                    count--;
                }
                left++;
            }
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
    }
};