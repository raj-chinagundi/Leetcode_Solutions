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
    void reorderList(ListNode* head) {
              
        stack<ListNode*> st;
        
        ListNode *current = head;
        
        //add all the nodes to stack
        while(current){
            
            st.push(current);
            current = current->next; 
            
        }
        
        // point to the start
        current = head;
        int n = st.size();
        
        if(n<3) return;
        
        ListNode* next;
        
        for(int i=0;i<n/2;++i)
        {
            next = current->next;
            current->next = st.top();
            st.pop();
            
            current = current->next;
            current->next = next;
            current = current->next;
        }
        
        current->next = NULL;  
    }
};