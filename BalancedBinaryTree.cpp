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
    int treeDeepth(TreeNode *root){
        int result = 0;
        if(root){
            result++;
            int l = treeDeepth(root->left);
            int r = treeDeepth(root->right);
            if(l > r)
                result += treeDeepth(root->left);
            else
                result += treeDeepth(root->right);
        }
        return result;
    }
    
    bool CheckBalancedAndDeepth(TreeNode *n, int* deepth){
        if(!n){
            if(deepth)
                *deepth = 0;
            return true;
        }
        
        int left_deepth = 0;
        int right_deepth = 0;
        if(!CheckBalancedAndDeepth(n->left, &left_deepth)
            || !CheckBalancedAndDeepth(n->right, &right_deepth)){
            return false;
        }
        
        if(deepth)
            *deepth = (left_deepth > right_deepth ? left_deepth : right_deepth) + 1;
        
        return (abs(left_deepth - right_deepth) <= 1);
    }
    
    /*返回高度，若不平衡返回 -1 */
    int CheckBalanced(TreeNode *n){
        if(!n){
            return 0;
        }
        
        int left_deepth = CheckBalanced(n->left);
        int right_deepth = CheckBalanced(n->right);
        if(left_deepth < 0 || right_deepth < 0)
            return -1;
        
        if(abs(left_deepth - right_deepth) > 1)
            return -1;
        
        return (left_deepth > right_deepth ? left_deepth : right_deepth) + 1;
    }

    bool isBalanced(TreeNode *root) {
        // while(1){
        //     int left_deepth = treeDeepth(root->left);   
        //     int right_deepth = treeDeepth(root->right);
        //     if(abs(left_deepth-right_deepth) > 1)
        //         return false;
        //     return isBalanced(root->left) && isBalanced(root->right);
        // }
        return CheckBalanced(root) >= 0;
    }
};
