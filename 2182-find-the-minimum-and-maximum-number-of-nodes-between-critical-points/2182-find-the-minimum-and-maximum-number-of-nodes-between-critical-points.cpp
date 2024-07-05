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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //if(head->next->next == NULL)return {-1,-1};

        ListNode* prev = head, *curr = head->next, *sec = head->next->next;
        int maxi = INT_MIN, mini = INT_MAX;
        vector<int> temp;
        int aux = 1;
        while(sec!=NULL){
            if((curr->val > prev->val) && (curr->val > sec->val)){
                temp.push_back(aux);
            }
            if((curr->val < prev->val) && (curr->val < sec->val)){
                temp.push_back(aux);
            }
            prev = curr;
            curr = sec;
            sec = sec->next;
            aux++;
        }
        if(temp.size()<=1)return {-1, -1};

        else{
            for(int i=1;i<temp.size();i++){
                //maxi = max(maxi, temp[i]-temp[i-1]);
                mini = min(mini, temp[i]-temp[i-1]);
            }
            maxi = temp[temp.size()-1]-temp[0];
        }
        return {mini, maxi};
    }
};