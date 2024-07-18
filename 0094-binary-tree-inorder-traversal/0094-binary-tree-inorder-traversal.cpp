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
    vector<int> inorderTraversal(TreeNode* root) {
        // this is iterative inorder traversal - left, root, right

        // vector<int> in;
        // TreeNode * node = root;
        // stack<TreeNode*> st;
        // while(true){
        //     if(node == NULL){
        //         if(st.empty()==true)break;
        //         node = st.top();
        //         st.pop();
        //         in.push_back(node->val);

        //         node = node->right;
        //     }
        //     else{
        //         st.push(node);
        //         node = node->left;
        //     }
        // }
        // return in;



























        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> in;
        while(true)
        {
            if(node == NULL){
                if(st.empty() == true)break;
                else{
                    node = st.top();
                    st.pop();
                    in.push_back(node->val);
                    node = node->right;
                }
            }
            else{
                st.push(node);
                node = node->left;
            }
        }
        return in;


















    }
};