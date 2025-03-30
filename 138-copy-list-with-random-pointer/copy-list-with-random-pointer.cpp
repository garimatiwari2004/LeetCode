/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>nodemap;
        if(!head) return nullptr;
        Node* temp=head;
        while(temp){
            nodemap[temp]=new Node(temp->val);
            temp=temp->next;

        }
        temp=head;
        while(temp){
            nodemap[temp]->next=nodemap[temp->next];
            nodemap[temp]->random=nodemap[temp->random];
            temp=temp->next;
        }
        return nodemap[head];
        
    }
};