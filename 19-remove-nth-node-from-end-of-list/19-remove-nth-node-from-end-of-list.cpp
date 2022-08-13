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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *s=head,*f=head;
        while(n--){
            f=f->next;
            if(f==NULL){
                return head->next;
            }
        }
        while(f->next!=NULL){
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return head;
    }
};