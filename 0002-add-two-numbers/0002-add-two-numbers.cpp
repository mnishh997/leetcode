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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1, *h2 = l2;
        int temp= 0;
        ListNode* h3 = new ListNode(0);
        ListNode* curr = h3;
        while(h1!=NULL || h2!=NULL){
            int sum = 0;
            if(h1!=NULL)sum+=h1->val;
            if(h2!=NULL)sum+=h2->val;
            sum+=temp;
            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
            
            temp = sum/10;
            if(h1!=NULL)h1=h1->next;
            if(h2!=NULL)h2=h2->next;
            
        }
        if(temp!=0){
            ListNode* node = new ListNode(temp);
            curr->next = node;
        }
        return h3->next;
    }
};