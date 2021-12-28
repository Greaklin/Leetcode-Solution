//Here is a C code, which is a solution to the first test form LeeCode website.
//The sum of two numbers.


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *result=NULL;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                 result=(int*)malloc(sizeof(int)*2);
                 result[0]=i;
                 result[1]=j;
                 *returnSize=2;//需要设置returnsize才可以！
                 return result;
            }
        }
    }
    *returnSize=0;
    return result;
}
