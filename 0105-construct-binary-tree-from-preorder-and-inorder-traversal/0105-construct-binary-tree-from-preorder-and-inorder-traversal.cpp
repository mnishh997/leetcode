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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& indMap){
        if((preStart > preEnd) || (inStart > inEnd))return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int indRoot = indMap[root->val];
        int numLeft = indRoot - inStart;

        root->left = buildTree(preorder, preStart+1, preStart + numLeft, inorder, inStart, indRoot - 1, indMap);

        root->right = buildTree(preorder, preStart + numLeft + 1, preEnd, inorder, indRoot + 1, inEnd, indMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]]= i;
        }
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder,0, inorder.size()-1, inMap);
        return root;
    }
};