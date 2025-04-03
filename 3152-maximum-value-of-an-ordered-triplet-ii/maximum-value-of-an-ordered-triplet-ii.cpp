class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long highest = 0; // to store highest number till now  : num[i]
        long long highest_diff = 0; // to store highest diff : num[i] - num[j]
        long long answer = 0; // to store current max value : ( num[i] - num[j] ) * num[k]
        for(long long num : nums) { 
            answer = max( answer , highest_diff * num); 
            highest_diff = max(highest_diff, highest - num);
            highest = max(highest, num);
        }
        return answer;
    
    }
};