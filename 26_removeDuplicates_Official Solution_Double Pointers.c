//这个双指针用的是int索引，主要是好短。。。。
//虽然和我的时间复杂度是一样的，空间复杂度也相近

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int fast = 1, slow = 1;//使用指针索引，重点是只能用int，比我之前的解法少了8bit的空间
    while (fast < numsSize) {
        if (nums[fast] != nums[fast - 1]) {//只要前后都不等就可以复制到slow
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}
