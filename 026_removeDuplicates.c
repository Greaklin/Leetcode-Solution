Solution01
//2022年01月06日晚10：46分开始
//O（1）的额外空间，哈希表算O1吗？不算，升序数组直接从头到尾遍历，前后一致就删除，前后不一致就再见
//使用三指针，直接跳就可以了，不需要移动
//用时1.5小时
//执行361例子使用12ms击败85%消耗内存7.4MB击败50%
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0)//如果nums为空或numsSize = 0，则直接返回
        return 0;
    int *p = nums + 1, *jd = nums;//p,nums和基点三指针遍历，基点指针用于配合p指针向后进行遍历
    int length = numsSize;//定义为返回长度
    short flag = 0;//出现重复数标志
    int i = 1;
    for(; i < numsSize; i++){//p作为向后遍历的指针，i跟着p动
        if(*jd == *p){//如果当前便利的基点等于后续位，则*p继续加，基点指针停止
            p++;
            length--;
            flag = 1;//表明出现重复数
        }
        else if(flag == 1 && *jd != *p){//若当前基点位不等于p位数且之前出现过重复数，基点位赋值给当前nums位置，nums加加，基点移动到p的位置
            *nums = *jd;//当前nums等于基点位置的数
            nums++;//nums向前移动
            jd = p;//基点移动到p的位置
            p++;//p继续向前移动
            flag = 0;
        }
        else {//若什么都没发生则三个一起加
            *nums = *jd;//基点值赋给nums
            nums++;
            jd++;
            p++;       
        }
    }
    if(*nums != *jd){//最后将nums和基点同步
        *nums = *jd;
    }
    return length;
}


OfficialSolution
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
