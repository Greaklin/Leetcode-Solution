//2022年01月21日
//树的深度优先遍历算法，即先根（前序）遍历算法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int gg = 0;
int max = 0;

void dep(struct TreeNode* root){
    gg++;//进入时gg++
    if(root->left == NULL && root->right == NULL)//若当前遍历根的左右节点都是空的，则说明是叶子节点
        if(gg>=max)
            max = gg;
    if(root->left != NULL) {
        dep(root->left);
        gg--;//回退时gg--
    }
    if(root->right != NULL){
        dep(root->right);
        gg--;  
    } 
}

int maxDepth(struct TreeNode* root){
    gg = 0;
    max = 0;
    if(root != NULL) dep(root);
    return max;
}
