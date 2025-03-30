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
        if (!head) return nullptr;

        // Step 1: Clone nodes and insert them in between
        Node* temp = head;
        while (temp) {
            Node* clone = new Node(temp->val);
            clone->next = temp->next;
            temp->next = clone;
            temp = clone->next;
        }

        // Step 2: Assign random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Separate the cloned list from original
        temp = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        while (temp) {
            temp->next = temp->next->next;
            if (copy->next)
                copy->next = copy->next->next;
            temp = temp->next;
            copy = copy->next;
        }

        return newHead;
        
    }
};