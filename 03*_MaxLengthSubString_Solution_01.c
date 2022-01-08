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
