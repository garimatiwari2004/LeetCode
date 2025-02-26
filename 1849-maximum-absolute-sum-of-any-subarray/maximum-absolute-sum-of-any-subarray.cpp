class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum=0, negSum=0, maxPos=0, maxNeg=0;
        for(int i=0; i<nums.size(); i++) {
            posSum += nums[i];
            negSum += nums[i];
            if(posSum < 0) posSum = 0;
            if(negSum > 0) negSum = 0;
            maxPos = max(maxPos, posSum);
            maxNeg = max(maxNeg, abs(negSum));
        }
        return max(maxPos, maxNeg);
    }
};