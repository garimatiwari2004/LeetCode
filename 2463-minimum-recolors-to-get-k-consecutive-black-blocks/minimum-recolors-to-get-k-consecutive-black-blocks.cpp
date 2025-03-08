class Solution {
public:
    int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
    int minRecolors = k; // Maximum possible recolors is k
    int currentRecolors = 0;

    // Count 'W' in the first window of size k
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') 
            currentRecolors++;
    }
    minRecolors = currentRecolors;

    // Sliding window: move the window across the string
    for (int i = k; i < n; i++) {
        // Remove leftmost element from previous window
        if (blocks[i - k] == 'W') 
            currentRecolors--;
        // Add the new rightmost element
        if (blocks[i] == 'W') 
            currentRecolors++;

        // Update minimum recolors needed
        minRecolors = min(minRecolors, currentRecolors);
    }

    return minRecolors;

    }
};