//2022年1月20日
//执行用时0ms，内存消耗5.7MB，测试用例68个，击败100%与82.27%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void pos(struct TreeNode* root, int* returnSize, int* ret){
    if(root == NULL)
        return;
    pos(root->left, returnSize, ret);//后续左右根
    pos(root->right, returnSize, ret);//后续左右根  
    ret[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = malloc(400);
    *returnSize = 0;
    pos(root,returnSize,ret);
    *returnSize--;
    return ret;
}
