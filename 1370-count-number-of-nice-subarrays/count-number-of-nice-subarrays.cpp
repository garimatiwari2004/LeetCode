class Solution {
public:
vector<int>convert(vector<int>&nums){
    vector<int>ans;
    for(int n:nums){
        ans.push_back(n%2);
 }
 return ans;
}


    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>converted=convert(nums);
        unordered_map<int,int>map;
        int count=0;
        int sum=0;
        map[0]=1;
        for(int n:converted){
            sum+=n;
            if(map.find(sum-k)!=map.end()){
                count+=map[sum-k];
            }
            map[sum]++;

        }
        return count;
        
    }
};