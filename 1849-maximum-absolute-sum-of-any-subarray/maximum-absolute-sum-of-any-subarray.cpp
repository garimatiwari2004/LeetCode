class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxs=INT_MIN;
        int mins=INT_MAX;
        int minsum=0;
        int maxsum=0;
        for(int num:nums){
            minsum+=num;
            maxsum+=num;
            maxs=max(minsum,maxs);
            mins=min(maxsum,mins);
            if(minsum<0) minsum=0;
            if(maxsum>0) maxsum=0;
        }
        return max(abs(mins),maxs);
        
    }
};