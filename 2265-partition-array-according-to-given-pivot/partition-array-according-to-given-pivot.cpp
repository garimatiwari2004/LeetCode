class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>low,high,result(nums.size());
        int count=0;
        for(int num :nums){
            if(num<pivot) low.push_back(num);
            else if(num==pivot) count++;
            else high.push_back(num);

        }
        int index=0;
        for(int n : low) result[index++]=n;
        for(int i=0;i<count;++i) result[index++]=pivot;
        for(int n:high) result[index++]=n;
        return result;
        
    }
};