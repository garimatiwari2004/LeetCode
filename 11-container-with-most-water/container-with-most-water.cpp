class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxArea = 0;
        
        while (i < j) {
            int w = j - i;
            int h1 = height[i], h2 = height[j];
            int h = min(h1, h2);
            maxArea = max(maxArea, h * w);
            // Greedily moving Pointers
            h1 > h2 ? j-- : i++;
        }
        
        return maxArea;
    }
};