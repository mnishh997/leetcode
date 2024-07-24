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
    TreeNode* h(vector<int>& preorder, vector<int>&inorder, int pre_start, int pre_end, int in_start, int in_end, unordered_map<int,int>& m){
        if(pre_start>pre_end || in_start>in_end)return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        int ind_root = m[preorder[pre_start]];
        int numLeft = ind_root-in_start;

        root->left = h(preorder,inorder,  pre_start+1, pre_start+numLeft, in_start, ind_root-1, m);
        root->right = h(preorder, inorder, pre_start+numLeft +1, pre_end, ind_root+1, in_end, m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root = h(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, m);
        return root;
    }
};