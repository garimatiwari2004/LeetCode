using System;
using System.Linq;

public class Solution {
    public int MaximumCandies(int[] candies, long k) {
        int l = 1;
        int r = candies.Max(); // Maximum candy pile size

        while (l <= r) {
            int m = (l + r) / 2; // Mid value for binary search
            long count = 0;

            // Calculate how many children can receive at least `m` candies
            foreach (int candy in candies) {
                count += candy / m;
            }

            // If we can serve at least `k` children, try a larger pile size
            if (count >= k) {
                l = m + 1;
            } 
            // Otherwise, reduce the pile size
            else {
                r = m - 1;
            }
        }
        
        return r; // Maximum valid pile size
    }
}
