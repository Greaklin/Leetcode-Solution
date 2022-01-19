//2022年01月19日
//复习一下二叉树
//执行时间0ms，击败100%，内存消耗5.7MB，击败83.86%
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
 //此题的returnsize和第一题的一样，都是作为返回值数组的最大元素个数索引使用。
 //如果不顾空间复杂度可以直接malloc 100个单位的int然后用returnsize做索引，然后树的前序遍历按照顺序直接逐个填入malloc的数组里即可
 //如果要顾及空间复杂度，emm一个思路是额外构造一个链式存储数据结构，第二个是动态线性表，不过动态线性表万一空间不足需要额外开辟空间。
 //不行，int*的返回值类型不允许动态线性表吧，还是直接写100吧。
 //先递归写一波，明天再搞循环的前序遍历
void pre(struct TreeNode* root,int* rt,int* returnSize){//递归函数
    if(root == NULL)
        return;
    rt[(*returnSize)++] = root->val;//将当前节点的值写入数组
    pre(root->left,rt,returnSize);//遍历左节点
    pre(root->right,rt,returnSize);//遍历右节点
    return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* rt = malloc(400);//直接开始就开辟400字节的空间，不考虑空间复杂度直接暴力求解
    *returnSize = 0;
    pre(root,rt,returnSize);//开始递归前序遍历
    *returnSize--;//减去多加的1个returnSize
    return rt;
}
