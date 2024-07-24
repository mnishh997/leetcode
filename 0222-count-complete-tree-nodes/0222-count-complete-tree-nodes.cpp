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
    int L_height(TreeNode* node){
        int cnt=0;
        while(node!=NULL){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    int R_height(TreeNode* node){
        int cnt=0;
        while(node!=NULL){
            cnt++;
            node=node->right;
        }
        return cnt;
    }
    public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=L_height(root->left);
        int rh=R_height(root->right);
        if(lh==rh){
            //so basically it is 2^h
            return (1<<(lh+1))-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
};