//2022年01月09日：今日先跳过Z字转换，时间不太够，速度解决这题
//这个不是双指针吗？和26一毛一样,不完全一样。。。
int removeElement(int* nums, int numsSize, int val){
   int i = 0, j = 0;
   if(numsSize == 0 || (numsSize ==1 && nums[0] != val))//特殊情况，如果直接进入下面的循环在只有1位的情况下j<numsSize-1会直接删掉首位
        return numsSize;
   while(j < numsSize - 1){//这里的numsSize必须是-1的，有坑，不然j会索引nums到外面，但还是爆了日
        while(j < numsSize - 1 && nums[j] == val) j++;//如果当前的nums[j]取等就跳过这个元素   
        if (j < numsSize -1) nums[i++] = nums[j++];
   }
   if(nums[j] != val) nums[i++] = nums[j];//补一手对[0，0，0，0]3这类输入的空缺和[4,5] 4这类输入的
   return i;
}

//6次解答通过，执行用时0-4ms击败100%-60%，内存消耗6MB-6.1MB击败22.62%-5%
