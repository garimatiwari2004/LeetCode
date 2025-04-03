class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n=nums.size();
            vector<int>maxleft(n);
            maxleft[0]=nums[0];
            for(int i=1;i<n;++i){
                maxleft[i]=max(maxleft[i-1],nums[i-1]);
            }
            vector<int>maxright(n);
            for(int i=n-2;i>=0;--i){
                maxright[i]=max(maxright[i+1],nums[i+1]);
            }
            long long ans=0;
            for(long long mid=1;mid<n-1;++mid){
                long long leftmax=maxleft[mid];
                long long rightmax=maxright[mid];
                long long tripval=(leftmax-nums[mid])*rightmax;
                ans=max(ans,tripval);

            }
               return ans;                    
        }
    } ;