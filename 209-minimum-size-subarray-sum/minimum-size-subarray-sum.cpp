class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), l=0,s=0,m=INT_MAX;
        for(int r=0;r<n;r++){
            s+=nums[r];
            while(s>=target){
                m=min(m,r-l+1);
                s-=nums[l];
                l++;
            }
        }
        return (m==INT_MAX)?0:m;
    }
};