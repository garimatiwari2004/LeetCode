class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         unordered_map<int, int> node, color;
        vector<int> result;

        for (auto& q : queries) {
            int x = q[0], y = q[1];

            if (node.count(x)) {
                int prevColor = node[x];
                if (prevColor == y) {
                    result.push_back(color.size());
                    continue;
                }
                if (--color[prevColor] == 0) color.erase(prevColor);
            }

            node[x] = y;
            color[y]++;
            result.push_back(color.size());
        }

        return result;
        
    }
};