Solution01
//2022年01月22日
//张大木的答案
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int targetSum){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) {
        if(targetSum == root->val) return true;
        else return false;
    }
    if(root->left != NULL && hasPathSum(root->left, targetSum - root->val)) return true;
    if(root->right != NULL && hasPathSum(root->right, targetSum - root->val)) return true;
    return false;
}
