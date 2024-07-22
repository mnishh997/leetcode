/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<ll, TreeNode*>> q;

        q.push({0, root});
        ll res = 0;
        while(!q.empty()){
            ll sz = q.size();
            ll start=INT_MAX, end=0;
            ll min_ind = q.front().first;
            while(sz--){
                ll ind = q.front().first-min_ind;
                TreeNode* node = q.front().second;
                start = min(start, ind);
                end = max(end, ind);

                q.pop();

                if(node->left != NULL)q.push({2*ind +1, node->left});
                if(node->right != NULL)q.push({2*ind+2, node->right});
            }
            res = max(res,end-start+1);
        }return res;
    }
};