//本算法的思想与之前的解法思想上一致使用的是滑动窗口的思想，但解法不同点在于数据结构查找由链表改成了散列表，索引会更快一些
//同时使用双指针进行查表
//最终运行结果相较于链表表现效果更好了8ms左右（运行948个案例输入不知道有多少反正挺多的情况下）
//应该在内存调用等方面可以做进一步的优化

#define MaxSize 96          //所有可显示ASCII字符都囊括在内
int HashFunc(const char s){
    return (int)(s-31);//将传入的字符参数转换成整形值
}

int delete(int fst, int *Hash, int num){//传入元素头指针的数值，在哈希表中删除索引位i之前对应位数的最小值
    for(int i = 0; i < MaxSize;i++)
        if(Hash[i]<=num && Hash[i]!= 0){//如果表中元素小于num值，则赋值为0,fst所指位置加1
            Hash[i] = 0;
            fst++;
        }
    return fst;
}

int lengthOfLongestSubstring(char * s){
    int *HashTable = (int*)malloc(sizeof(int)*MaxSize);//建立哈希表
    memset(HashTable,0,MaxSize*4);//初始化哈希表全为0
    int Max = 0, i = 0;//记录历史最大长度和当前长度
    int fst = 0, sec = 0;//遍历子串的头尾指针赋初值，都是第一个s的位置
    while(*s){
        i = HashFunc(*s);//用局部变量记录当前的s在哈希表中应当在的位置
        if(HashTable[i]){//若当前的s字符已经在表中，则头指针向后移动，同时更新最大值
            if(Max < sec - fst)
            Max = sec - fst;//如果Max小于当前子串长度则更新Max值
            fst = delete(fst,HashTable,HashTable[i]);//更新头指针位置，等价于更新子串长度窗口
        }
        sec++;//遍历到新的一位时尾指针加1，自加一定要放在当前元素入表之前
        HashTable[i] = sec;//将当前元素入表，则把当前遍历的位置赋值给该位
        s++;//判定下一个字符
    }
    return Max>(sec - fst)? Max:(sec - fst);//返回
}
