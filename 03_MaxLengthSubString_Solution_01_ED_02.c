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
