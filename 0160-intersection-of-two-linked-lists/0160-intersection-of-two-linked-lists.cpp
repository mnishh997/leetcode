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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA, *h2 = headB;
        while(h1!=NULL){
            h1->val = -1*(h1->val);
            h1 = h1->next;
        }
        while(h2!=NULL){
            if(h2->val<0){
                break;
            }
            else{
                h2 = h2->next;
            }
        }
        ListNode* t = headA;
        while(t!=NULL){
            t->val = t->val*-1;
            t = t->next;
        }
        return h2;
        
    }
};