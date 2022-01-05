//2022.01.05
//今天在昨天的基础上进行了改进，成功通过，测试用例11510个执行用时4ms，击败94.39%，关键点在于15行位置的判断还有10行需要用long，否则当x足够大时level将会溢出，使用long保证运算时潜在使用的是整形

bool isPalindrome(int x){
    if(x<0)//如果输入小于0则直接返回失败
    return false;
    if(x == 0)
    return true;
    //首先得判断x多大
    long level = 1;//记录输入x的数量级（不用long可能level会溢出）
    long fz = 1;
    while((int)(x/level)) level*=10;//利用int类型向0取整特性，得到x的数量级，虽然用的除法有点难顶
    level = level/10;//恢复x的数量级
    while((x/level)<(x/fz)){//当比较过中位数之后则停止,//注意，此处x不能等于0！不然Leetcode会报错
        if((x/level)!=(x%(10*fz)/fz))//该步的判断是核心难点，x/level为当前当前数量级，但每次x的个位数都需要单独拿出来，单独拿出x的某个位需要用(x%(10*fz)/fz)表达式结合19行的变化，先x取余比其高一位的再除
        return false;
        x = x%level;//去掉x的最高位数，直接取余数
        level /= 10;
        fz *=10;
    }
    return true;
}
