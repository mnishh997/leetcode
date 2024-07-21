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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool f = 0;
        vector<vector<int>> res;
        vector<int> temp;

        queue<TreeNode*> q;
        if(root == NULL)return res;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            if(f==0){
                f=1;

            }
            else{
                reverse(temp.begin(), temp.end());
                f=0;
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};