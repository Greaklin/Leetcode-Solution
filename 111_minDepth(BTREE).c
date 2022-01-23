Solution01
//2022年01月22日
//张大木的答案哈哈哈
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int gg = 0;
int min = 0;

void dep(struct TreeNode* root){
    gg++;//进入时gg++
    if(root->left == NULL && root->right == NULL)//若当前遍历根的左右节点都是空的，则说明是叶子节点
        if(gg<=min)
            min = gg;
    if(root->left != NULL) {
        dep(root->left);
        gg--;//回退时gg--
    }
    if(root->right != NULL){
        dep(root->right);
        gg--;  
    } 
}

int minDepth(struct TreeNode* root){
    gg = 0;
    min = 1000000;
    if (root == NULL) return 0;
    if(root != NULL) dep(root);
    return min;
}

//2022年01月23日
//今日彩蛋，啥都没有
