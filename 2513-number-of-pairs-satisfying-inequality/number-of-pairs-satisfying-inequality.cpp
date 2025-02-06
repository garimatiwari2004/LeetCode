class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // first i have to make compressed indices array
        int n = int(nums1.size());
        vector<int> x(n,0);
        for(int i=0; i<n; i++){
            x[i] = nums1[i] - nums2[i];
        }
        //compressed
        map<int,int> compressed;
        vector<int>sortedX;
        vector<int>compressedX(n,0);
        sortedX = x;
        sort(sortedX.begin(), sortedX.end());
        // we have give dome index to each of the values
        int idx=1;
        for(auto it:sortedX){
            if( compressed.find(it) == compressed.end() ){
                compressed[it] = idx++;
            }
        }
        // compressedX
        for(int i=0; i<n; i++){
            compressedX[i] = compressed[x[i]];
        }
        // made the compressedx array also
        // now making the segment trees
        vector<int> tree( 4*idx, 0 );
        // updating the segment tree at some index we are putting some value
        function<void(int, int, int, int, int)>update = [&](int index, int value, int node, int node_left, int node_right){
            if( node_left == node_right ){
                tree[node]+=value;
                return;
            }
            int mid = (node_left+node_right)/2;
            if( index <= mid ) update( index, value, node*2 , node_left, mid );
            else update( index, value, node*2+1, mid+1, node_right );
            tree[node] = tree[node*2]+tree[node*2+1];
        };
        // returns the sum from query_left to query_right
        function<int(int, int, int, int, int)>query = [&](int node, int node_left, int node_right, int query_left, int query_right){
            if( node_left > query_right || node_right < query_left ){
                return 0;
            }
            if( query_left <= node_left && query_right >= node_right ){
                return tree[node];
            }
            int last_in_left = (node_left + node_right)/2;
            return query(node*2, node_left, last_in_left, query_left, query_right) +
                   query(node*2+1, last_in_left+1, node_right, query_left, query_right);
        };
        long long ans=0;
        for(int i = x.size()-1; i>=0; i--){
            int target = x[i]-diff;
            auto it = compressed.lower_bound( target );
            if( it!=compressed.end() ){
                int target_index = it->second;
                ans+=query( 1, 1, idx, target_index, idx );
            }
            update( compressedX[i], 1, 1, 1, idx );
        }
        return ans;
    }
};