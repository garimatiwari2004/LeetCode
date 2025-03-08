class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int maxlen = 0;
        int left = 0;
        int right = n-1;
        while(left < right){
            maxlen = Math.max(maxlen, (right - left) * Math.min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxlen;
    }
}