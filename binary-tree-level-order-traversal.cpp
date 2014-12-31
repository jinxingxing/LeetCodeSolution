/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rv;
        vector<TreeNode*> this_nodes, next_nodes;
        if(root)
            this_nodes.push_back(root);
            
        while(!this_nodes.empty()){
            vector<int> this_level;
            this_level.clear();
            next_nodes.clear();
            for(size_t i=0; i<this_nodes.size(); i++){
                TreeNode* node = this_nodes[i];
                this_level.push_back(node->val);
                
                if(node->left) next_nodes.push_back(node->left);
                if(node->right) next_nodes.push_back(node->right);
            }
            
            this_nodes.swap(next_nodes);
            rv.push_back(this_level);
        }
        
        return rv;
    }
};
