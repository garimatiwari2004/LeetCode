class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negcount=0;
        int poscount=0;
        for(int i: nums){
            if(i==0) continue;
            if(i>0) poscount++;
            else negcount++;
        }
        return max(poscount,negcount);
    }
};