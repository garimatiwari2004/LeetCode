class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int c=nums[0];
        int m=nums[0];
       // int sum=0;
        for(int i=1;i<nums.size();++i){
            c=nums[i]>nums[i-1]?c+nums[i]:nums[i];
            m=max(m,c);
        }
        return m;
    }
};