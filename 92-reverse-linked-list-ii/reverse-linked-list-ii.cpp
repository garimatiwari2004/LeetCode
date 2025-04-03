/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevNode=NULL;
        ListNode* curr=head;
        int i;
        for(i=1;i<left;++i){
            prevNode=curr;
            curr=curr->next;
        }
        ListNode* revhead=curr;
        ListNode* revtail=NULL;
        while(i<=right){
            ListNode* nextnode=curr->next;
            curr->next=revtail;
            revtail=curr;
            curr=nextnode;
            i++;
        }
        if(prevNode) prevNode->next=revtail;
        else head=revtail;
        revhead->next=curr;
        return head;
        
    }
};