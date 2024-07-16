#include <string>
#include <algorithm>
using namespace std;

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
    bool findPath(TreeNode* root, int value, string& path) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == value) {
            return true;
        }
        path.push_back('L');
        if (findPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        // Find the first position where the paths differ
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        // Create the result path: U for each remaining step in pathToStart and then the remaining pathToDest
        string result(pathToStart.size() - i, 'U');
        result += pathToDest.substr(i);
        
        return result;
    }
};
