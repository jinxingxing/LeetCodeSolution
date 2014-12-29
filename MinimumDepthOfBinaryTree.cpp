/**
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        
        int l_min_depth = 0, r_min_depth = 0;
        if(root->left && root->right){
            l_min_depth = minDepth(root->left);
            r_min_depth = minDepth(root->right);
            return min(l_min_depth, r_min_depth) + 1;
        }
        else if(root->left){
            l_min_depth = minDepth(root->left);
            return l_min_depth + 1;
        }
        else if(root->right){
            r_min_depth = minDepth(root->right);
            return r_min_depth + 1;
        }else{
            return 1;
        }
    }
};
