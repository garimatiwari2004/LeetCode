class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long good=0;
        long long n=nums.size();
        for(int i=0;i<n;++i){
            int diff=nums[i]-i;
            good+=m[diff];
            m[diff]++;
        }
        return (n*(n-1))/2-good;
        
    }
};