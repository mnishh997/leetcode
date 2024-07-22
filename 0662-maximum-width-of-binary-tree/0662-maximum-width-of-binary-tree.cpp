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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long start = q.front().second; // Index of the first node in the current level
            unsigned long long end = q.back().second;   // Index of the last node in the current level
            ans = max(ans, int(end - start + 1));       // Update the maximum width

            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();

                // Normalize index to prevent overflow
                unsigned long long normalizedIndex = index - start;

                if (node->left) q.push({node->left, 2 * normalizedIndex});
                if (node->right) q.push({node->right, 2 * normalizedIndex + 1});
            }
        }

        return ans;
    }
};
