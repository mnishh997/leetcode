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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head, *sec = head->next;
        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = sec;
            if(sec!=NULL)sec = sec->next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            len++;
            curr= curr->next;
        }
        if(len == 1)return true;
        int temp = len/2;
        curr = head;
        temp --;
        while(temp--){
            curr = curr->next;
        }
        ListNode* headd = curr->next;
        if(len%2==1){
            headd = headd->next;
        }
        curr->next = NULL;
        ListNode* headdd = reverse(head);
        ListNode* t1 = headd, *t2 = headdd;
        while(true){
            if(t1==NULL && t2 == NULL)return true;
            if(t1->val != t2->val){
                return false;
            }
            t1=t1->next;
            t2 = t2->next;
        }
        return true;
    }
};