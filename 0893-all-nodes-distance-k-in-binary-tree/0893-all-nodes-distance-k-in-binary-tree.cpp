/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // first of all store parents
        unordered_map<TreeNode*, TreeNode*> m;

        queue<TreeNode*> q;
        TreeNode* n = new TreeNode(-1);
        q.push(root);
        m[root] = n;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left !=NULL){
                q.push(node->left);
                m[node->left] = node;
            }
            if(node->right != NULL){
                q.push(node->right);
                m[node->right] = node;
            }
        }
        /////now i have parent of all the nodes
    vector<int> vis(501, 0);
        int dist = 0;
        vector<int> res;
        q.push(target);
        vis[target->val]=1;
        while(dist<k){
            int sz = q.size();
            dist++;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                TreeNode* par = m[node];
                // now i will try to go to left, to parent and to right

                //trying to go to left
                if(node->left!=NULL && vis[node->left->val]==0){
                    q.push(node->left);
                    vis[node->left->val]=1;
                }
                //now right
                if(node->right != NULL && vis[node->right->val]==0){
                    q.push(node->right);
                    vis[node->right->val]=1;
                }

                //now try to go to parent

                if(par!=n && vis[par->val]==0){
                    q.push(par);
                    vis[par->val]=1;
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};