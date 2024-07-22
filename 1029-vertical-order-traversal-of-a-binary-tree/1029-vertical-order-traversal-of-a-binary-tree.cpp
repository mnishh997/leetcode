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
        map<int,map<int,multiset<int>>> nodes;

        queue<pair<TreeNode*,pair<int,int>>> q; 

        q.push({root,{0,0}});

        while(!q.empty())
        {
            TreeNode* n = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            nodes[vertical][level].insert(n->val);
            q.pop();

            if(n->left!=NULL) q.push({n->left,{vertical-1,level+1}});
            if(n->right!=NULL) q.push({n->right,{vertical+1,level+1}});

        }
        vector<vector<int>> ans ;
        for(auto p: nodes){
            vector<int> aux ;
            for(auto q : p.second){
                aux.insert(aux.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(aux);
        }
        return ans;
    }
};