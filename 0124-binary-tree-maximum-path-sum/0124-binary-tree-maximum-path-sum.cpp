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
    int h(TreeNode* root, int& res){
        if(root == NULL)return 0;
        int temp = max(0, h(root->left, res));
        int aux = max(0,h(root->right, res));
        res = max(res, root->val+ aux+temp);

        return root->val + max(aux, temp);
        //return h(root->left) + h(root->right) + root->val;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        stack<TreeNode*> st;
        vector<TreeNode*> v;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            v.push_back(node);

            if(node->right!=NULL)st.push(node->right);
            if(node->left != NULL)st.push(node->left);
        }
        int res = -1e9;
        for(auto it : v){
            h(it, res);
        }
        return res;
    }
};