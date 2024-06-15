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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        sort(v.begin(),v.end());
        ListNode* h = head;
        int i=0;
        while(h!=NULL){
            h->val= v[i];
            i++;
            h=h->next;
        }
        return head;

    }

};