//2022年01月10日
//Double Pointer 01
//双指针基础解法
int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != val) {//不等的才进行赋值处理
            nums[left++] = nums[right];
        }
    }
    return left;
}
//基于官解对昨日代码进行优化如下：
int removeElement(int* nums, int numsSize, int val){
   short i = 0, j = 0;
   while(j < numsSize){//这里的numsSize必须是-1的，有坑，不然j会索引nums到外面，但还是爆了日 
        if (nums[j] != val) nums[i++] = nums[j];//此处逻辑反取nums[j]！=val则可以省略原解其他的判断步骤，绝了
        j++;
   }
   return i;
}
//运行速度快于官解，内存消耗和官解一个数量级

//答案思路2和快速排序的核心思想一致，左右开弓，但是是从右边进行减长，只需要便利一次即可
//算法思路为：
//从左边开始往右，碰到等于val的则把右边不等于val的移到左边的这个位置覆盖，然后总长度减x，x为右指针移动的次数
//因为不需要交换元素
int removeElement(int* nums, int numsSize, int val) {
    int left = 0, right = numsSize;
    while (left < right) {//当左指针小于右指针时代码继续运行
        if (nums[left] == val) {//左指针所指为val时则开始找右指针
            nums[left] = nums[right - 1];
            right--;
        } else {//左指针所指非val时左指针继续向左
            left++;
        }
    }
    return left;
}
