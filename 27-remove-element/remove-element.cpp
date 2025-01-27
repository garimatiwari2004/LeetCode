class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        //hi
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};