/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* s=head,*f=head->next;
        while(s!=f){
            if(f==NULL || f->next==NULL){
                return false;
            }
            s=s->next;
            f=f->next->next;
        }
        return true;
    }
};