/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        vector<TreeNode*> this_nodes, next_nodes;
        if(!root) return true;
        
        this_nodes.push_back(root);
        while(!this_nodes.empty()){
            next_nodes.clear();
            for(size_t i=0; i<this_nodes.size(); i++){
                if(i<this_nodes.size()/2){
                    size_t si = this_nodes.size()-1-i;
                    if(this_nodes[i] == NULL && this_nodes[si] == NULL){
                        /* nothing */
                    }
                    else if(this_nodes[i] == NULL && this_nodes[si] != NULL)
                        return false;
                    else if(this_nodes[i] != NULL && this_nodes[si] == NULL)
                        return false;
                    else if(this_nodes[i]->val != this_nodes[si]->val)
                        return false;
                }
                TreeNode* node = this_nodes[i];
                if(node){
                    next_nodes.push_back(node->left);
                    next_nodes.push_back(node->right);
                }
            }
            this_nodes.swap(next_nodes);
        }
        
        return true;
    }
};
