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
    vector<int> postorderTraversal(TreeNode* root) {
        // this is iterative postorder traversal = left, root, right

        vector<int> post;
        stack<TreeNode*> st;
        if(root == NULL) return post;
        TreeNode* node = root;
        st.push(node);

        while(!st.empty()){
            node = st.top();
            st.pop();
            if(node->left != NULL)st.push(node->left);
            if(node->right != NULL)st.push(node->right);
            post.push_back(node->val);
        }
        reverse(post.begin(), post.end());
        return post;
    }
};