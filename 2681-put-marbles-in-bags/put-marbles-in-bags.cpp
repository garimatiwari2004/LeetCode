class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
          int n = weights.size();
    if (k == 1) return 0; // No partitions, score remains the same

    vector<int> adj_sums;
    for (int i = 0; i < n - 1; i++) {
        adj_sums.push_back(weights[i] + weights[i + 1]);
    }

    sort(adj_sums.begin(), adj_sums.end()); 

    // Compute (k-1) smallest and largest sums
    long long min_score = accumulate(adj_sums.begin(), adj_sums.begin() + (k - 1), 0LL);
    long long max_score = accumulate(adj_sums.end() - (k - 1), adj_sums.end(), 0LL);

    return max_score - min_score;

        
    }
};