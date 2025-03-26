class Solution {
public:
    int jump(vector<int>& nums) {
        int minjumps=0;
        int currentjumpend=0;
        int maxreach=0;
        for(int i=0;i<nums.size()-1;++i){
            maxreach=max(maxreach,nums[i]+i);
            if(currentjumpend==i){
                minjumps++;
                currentjumpend=maxreach;

                if (currentjumpend >= nums.size() - 1) break;
            }

        }
        return minjumps;
    }
};