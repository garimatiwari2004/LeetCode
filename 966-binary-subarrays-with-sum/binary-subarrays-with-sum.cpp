class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>map;
        int sum=0;
        int count=0;
        map[0]=1;
        for(int n:nums){
            sum+=n;
            if(map.find(sum-goal)!=map.end()){
                count+=map[sum-goal];
            }
            map[sum]++;
        }
        return count;
    }
};