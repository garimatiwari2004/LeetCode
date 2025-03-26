class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        for(int i=0;i<nums.size();++i){
            if(maxreach<i) return false;
            maxreach=max(maxreach,nums[i]+i);    
        }
        return true;
    }
};