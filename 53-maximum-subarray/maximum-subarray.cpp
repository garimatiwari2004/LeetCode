class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxsofar=nums[0];
       int maxendinghere=nums[0];
       for(int i=1;i<nums.size();++i){
        maxendinghere=max(nums[i],maxendinghere+nums[i]);
        maxsofar=max(maxendinghere,maxsofar);
       // if(maxendinghere<0) maxendinghere=0;
       }
       return maxsofar;
        
    }
};