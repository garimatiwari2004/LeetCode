class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        vector<int>v;
        for(auto nums:nums1){
            v.push_back(nums);
        }
         for(auto nums:nums2){
            v.push_back(nums);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2!=0){
            return static_cast<double>(v[n / 2]);
        }
        return static_cast<double>((v[n/2]+v[n/2-1])/2.0);

        
    }
};