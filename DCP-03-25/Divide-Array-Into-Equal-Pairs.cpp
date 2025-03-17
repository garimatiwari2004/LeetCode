class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto num: nums) mpp[num]++;

        for(auto &it: mpp) if(it.second%2)return false;
        return true;
    }
};