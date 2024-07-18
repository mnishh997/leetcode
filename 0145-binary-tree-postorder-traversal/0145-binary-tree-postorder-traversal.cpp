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

        // inorder preorder postorder in just one iteration

        stack<pair<TreeNode*, int>> st;
        vector<vector<int>> v(3, vector<int>());
        if(root == NULL)return {};
        TreeNode* node = root;

        st.push({node, 0});

        while(!st.empty()){
            node = st.top().first;
            int num = st.top().second;

            if(num == 0){
                st.pop();
                v[num].push_back(node->val);
                st.push({node, 1});
                if(node->left!=NULL)st.push({node->left, 0});
            }
            if(num == 1){
                st.pop();
                v[num].push_back(node->val);
                st.push({node, 2});
                if(node->right!=NULL)st.push({node->right, 0});
            }
            if(num == 2){
                st.pop();
                v[num].push_back(node->val);
            }
        }
        return v[2];
    }
};