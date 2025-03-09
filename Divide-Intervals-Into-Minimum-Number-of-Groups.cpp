// Approach - 02 [ min-heap ]
class Solution {
public:
    int minGroups(vector<vector<int>>& inter) {
        int n = inter.size();

        // Sort based on interval starting value
        sort(inter.begin(), inter.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++) {
            int l = inter[i][0];
            int r = inter[i][1];

            if(pq.empty()){
                pq.push(r);
            }
            else{
                if(pq.top() >= l){
                    pq.push(r);
                }
                else{
                    pq.pop();
                    pq.push(r);
                }
            }
        }

        // The size of the set gives the number of groups
        return pq.size();
    }
};