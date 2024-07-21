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
    int h(TreeNode* root, int& ans){
        if(root == NULL)return ans;

        return max(h(root->left, ans), h(root->right, ans))+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int ans = 0;
        return max(h(root->left, ans)+h(root->right, ans),(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right))));
    }
};