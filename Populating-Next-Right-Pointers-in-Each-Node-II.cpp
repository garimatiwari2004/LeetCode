/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;  // Edge case: empty tree
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();  // Get the number of nodes at this level
            
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                
                // Connect the current node to the next node in the queue (if not last in the level)
                if (i != n - 1) {
                    node->next = q.front();
                }
                
                // Push left and right children into the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return root;
    }
};