#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            count += (right - left + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

