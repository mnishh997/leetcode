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
    void trav(TreeNode* root, int& sum){
        if(root==NULL)return;
        
        trav(root->right, sum);
        sum+=root->val;
        root->val = sum;
        trav(root->left, sum);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        //thinking of making a new traversal technique which is right, root, left
        // so
        int sum = 0;
        trav(root, sum);
        return root;
    }
};