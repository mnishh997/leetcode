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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // with no extra space

        ListNode* curr1 = list1, * curr2 = list2;
        ListNode* head = new ListNode(-101);
        if(curr1==NULL)return curr2;
        if(curr2 == NULL)return curr1;

        ListNode* next1 = curr1->next, *next2 = curr2->next;
        ListNode* last = head;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val == curr2->val){
                last->next = curr1;
                curr1->next = curr2;
                last = curr2;
                curr1 = next1;
                curr2 = next2;
                if(next1!=NULL)next1 = next1->next;
                if(next2!=NULL)next2 = next2->next;
            }
            else if(curr1->val > curr2->val){
                last->next = curr2;
                curr2 = next2;
                if(next2!=NULL)next2 = next2->next;
                last = last->next;
            }
            else{
                last->next = curr1;
                curr1 = next1;
                if(next1!=NULL)next1 = next1->next;
                last = last->next;
            }
        }
        if(curr1==NULL && curr2 != NULL){
            last->next = curr2;
        }
        else if(curr1!=NULL && curr2 == NULL)last->next = curr1;

        return head->next;
    }
};