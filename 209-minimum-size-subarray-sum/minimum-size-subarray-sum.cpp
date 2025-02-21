class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,len=INT_MAX;
        int n=nums.size();
        int sum=0;
        while(r<n){
            sum+=nums[r++];
            while(sum>=target){
                len=min(len,r-l);
                sum-=nums[l++];
            }
        }
        if(len==INT_MAX) return 0;
        else return len;
    }
};