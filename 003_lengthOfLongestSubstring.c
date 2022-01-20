//Solution01
//今天的代码存在bug！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！"didv"这种求出来是2不是3，已经过去三小时了为了完成这个，加油加油qwq，胜利就在眼前
//字符串的模式匹配算法，即KMP表构造类似
//算法设计要求：
//1.输出的最大值必须要是子串的长度
//2.子串中不允许重复字符
//算法的整体思路为：
//1、逐位读取传入字符串信息
//2、将读取到的字符串信息和字符表中已存在的字符进行对比
//3、发现一致则清空字符表，记录MAX值，重新开始记录字符表
//4、比较当前输出的MAX值是否大于之前最大的MAX，是则替换否则不用
//5、输出MAX值

//WrongED
struct Cptb{//比较表数据结构
    char value;
    struct Cptb *next;
};

typedef struct Cptb CPTB;

CPTB *delete(CPTB * head,char s){//递归释放链表函数
    while(head->value != s){//当没遍历到s的时候，持续释放链表前部空间
        CPTB *fz = head;//设置辅助变量记录head值
        head = head->next;//head向后移动
        free(fz);//释放前部空间   
    }
    CPTB *fz = head;//最后删除s值
    head = head->next;//head向后移动
    free(fz);//释放前部空间
    return head;//返回s后的表
}

int lengthOfLongestSubstring(char * s){
    CPTB *CMPtable = NULL, *tail = NULL, *p=NULL;//CMPtable作为字符串对照表的头指针，tail为辅助尾指针，p为辅助指针
    int max = 0, fz = 0;//最大串长和辅助串记录
    NEXT:
    while(*s){  
        if(!CMPtable){//字符串比较表未进行赋初值时，则赋值头表
            CMPtable = tail = (CPTB *)malloc(sizeof(CPTB));
            tail->next = NULL;//赋初值
        }
        else {//其他指针直接进行赋初值
            tail->next = malloc(sizeof(CPTB));
            tail->next->next=NULL;//next指针需要进行赋初值
            tail = tail->next;
        }
        tail->value = '\0';//赋初值,保证辅助指针p遍历到最后钱能停下来
        p = CMPtable;//赋值辅助指针作为遍历字符串链表辅助量
        while(p){//如果比较表中不存在当前s扫描到的元素，则max加1
            if(*s == p->value)
                if(fz>=max){//****此处一定要取等，否则会有返回值bug****为什么？自己写的代码自己看不懂？？？笑死qwq
                    max = fz;
                    fz = 0;
                    CMPtable = delete(CMPtable,*s);//释放原有链表的头部节点至与*s相同，重新构造
                    goto NEXT;//设置好开始新循环
                }
            p=p->next; //找表中下一个元素  
        }
        //达到此处说明该*s此时表中不存在
        tail->value = *s;
        fz ++;
        s++;//找字符串中的下一个字符进行比较
        //直接跳到下一次循环
    }
    return fz>max? fz:max;//如果fz大于max则返回fz，如果小于max则返回max
}

//ED02
//找出了昨天的逻辑bug，昨天并没有把无重复子串长度和链表的当前长度画上等号，而是使用了fz作为中间变量，且在查到重复变脸的时候不是将fz置为当前子串长度，而是直接将fz置0，导致子串长度和链表并不匹配，出现bug。
//今天还有另一个收获，知道了LeetCode的后台是使用连续调用的，他是重复调用子函数，而不是单个单个的历程测试，这样的话就要特别注意全局变量！
//代码思路总结：
//本解法的核心：链表长度等于子串长度。
//该算法仅需遍历一遍字符串，但每个元素都需要和子串中的所有元素进行比较，最坏情况下最大不连续子串就是母串，第一个比较0次，第二个比较1次....第n个比较n-1次，时间复杂度为O(n^2)，不够优秀。
//思路为将每个母串元素与当前记录的最长子串的内容一一比较，如果当前母串元素在子串中存在，则将子串元素从头开始删减，到和母串元素相同的那个元素为止，如果当前母串元素不在链表中，则什么都不做。
//每一次大循环的最后，将当前遍历到的母串元素入表。
//KMP算法的思想应该可以使用在这个题上，看看题解什么情况

typedef struct Cptb{//比较链表元素数据结构
    char value;
    struct Cptb *next;
}CPTB;

int length = 0;//全局变量记录链表当前长度

CPTB *delete(CPTB *head, char s){//递归释放链表函数
    if(head == NULL)//如果传入head为空，则直接返回
        return NULL;
    while(head->value != s){//当head的节点存在且没遍历到s的时候，持续释放链表前部空间
        CPTB *fz = head;//设置辅助变量记录head值
        head = head->next;//head向后移动
        free(fz);//释放前部空间
        length--;//该循环每执行一次链表当前长度减一   
    }
    if(head){//当head存在时（head下一个节点不存在则返回NULL）
        CPTB *fz = head;//最后删除s值
        head = head->next;//head向后移动
        free(fz);//释放前部空间 
        length--;
    }
    return head;//返回原表s之后的表
}

int lengthOfLongestSubstring(char * s){
    CPTB *CMPtable = NULL, *tail = NULL, *p=NULL;//CMPtable作为字符串对照表的头指针，tail为辅助尾指针，p为辅助指针
    int max = 0;//最大子串长
    length = 0;//反复调用，每次进来需要重新赋初值，否则无法多次调用！
    while(*s){  
        p = CMPtable;//赋值辅助指针作为遍历字符串链表辅助量
        while(p){//查找比较表中是否存在当前扫描到的元素
            if(*s == p->value){
                if(length>max){//如果检测到表中存在重复元素且此时表长大于max值，则删到该元素的下一个
                    max = length;
                }
                CMPtable = delete(CMPtable,*s);//释放原有链表的头部节点至与*s相同，重新构造
                break;//后续就不需要找了，因为之后的肯定都不一样
            }
            else
                p=p->next; //找表中下一个元素  
        }
        //调整了一下顺序，先查表，再加入
        if(!CMPtable){//字符串比较表未进行赋初值时，则赋值头表
            CMPtable = tail = (CPTB *)malloc(sizeof(CPTB));
            length++;//每分配一个空间链表长度加一
            tail->next = NULL;//将后续指针域赋初值
        }
        else {//后续表则继续添加
            tail->next = malloc(sizeof(CPTB));
            length++;//每分配一个空间链表长度加一
            tail = tail->next;
            tail->next=NULL;//next指针需要进行赋初值
        }
        tail->value = *s;
        s++;//继续下一个字符
    }
    return length>max? length:max;//如果fz大于max则返回fz，如果小于max则返回max
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//Solution02
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
