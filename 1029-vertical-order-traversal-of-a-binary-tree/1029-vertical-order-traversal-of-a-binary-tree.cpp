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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        vector<vector<int>> res;
        if(root == NULL)return res;

        queue<pair<int,pair<int,TreeNode*>>> q;
        q.push({0, {0, root}});

        while(!q.empty()){
            int vertical = q.front().first;
            int level = q.front().second.first;
            TreeNode* node = q.front().second.second;

            q.pop();
            m[vertical][level].insert(node->val);
            if(node->left != NULL){
                q.push({vertical-1, {level+1, node->left}});
            } 
            if(node->right!=NULL)q.push({vertical+1, {level+1, node->right}});
        }

        for(auto ver: m){
            vector<int> temp;
            for(auto level: ver.second){
                for(auto it: level.second){
                    temp.push_back(it);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};