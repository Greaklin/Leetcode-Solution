/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Listnode;


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int tmp;
    int c = 0;//进位数
    Listnode *L3 = malloc(sizeof(Listnode));//声明返回字符串,即新链表头节点
    L3->next = NULL;//**原本此处没加这个跑【0 0】出bug卡了一个小时
    Listnode *tmpcell = L3;//L3的尾指针tmpcell
    Listnode *p = l1;//辅助指针1，用于遍历链表l1
    Listnode *q = l2;//辅助指针2，用于遍历链表l2
    Listnode *t = tmpcell;//辅助指针3，临时保存尾指针
    while(q != NULL && p != NULL){
         tmp = p->val + q->val + c;  //将两对应位结果以及进位进行相加
        if(tmp>=10){//如果相加结果超过10则需要进位
            tmp -= 10;
            c=1;
        }
        else c=0;
        if(p->next && q->next){//尾插法建立新链表，如果l1和l2的下一位中存在0则不进行额外开辟空间
            tmpcell->next = (Listnode *)malloc(sizeof(Listnode));  
            tmpcell->next->next = NULL; 
        }//此段结合33行语句造成tmpcell变量不是链表尾指针
       
        tmpcell->val = tmp;
        t=tmpcell;//保留链表当前插入的前一个指针
        tmpcell = tmpcell->next;
        p = p->next;//p和q前进到链表的下一个变量
        q = q->next;
    }
    tmpcell = t;//将尾指针恢复，tmpcell此后继续作为尾指针
    while(p){//若p表还有剩余则继续复制
        tmpcell->next = (Listnode *)malloc(sizeof(Listnode));  //尾插
        tmpcell->next->next = NULL; 
        tmpcell = tmpcell->next;
        tmp = p->val + c;
        if(tmp>=10) {tmp-=10;c=1;}
        else c=0;
        tmpcell->val = tmp;//记得加上后续的进位
        p=p->next;
    }
    while(q){//q表同理
        tmpcell->next = (Listnode *)malloc(sizeof(Listnode));//尾插  
        tmpcell->next->next = NULL; 
        tmpcell = tmpcell->next;//移动到尾部节点
        tmp = q->val + c;
        if(tmp>=10) {tmp-=10;c=1;}
        else c=0;
        tmpcell->val = tmp;//记得加上后续的进位
        q=q->next;//进入下一个q表的尾节点
    }
    // tmpcell =t;//指针回溯,因为没有上述的while，此时尾指针其实是tmpcell，此句不注释则为bug
    if(c){//若最终结束了还有进位存在则进行补位
        tmpcell->next = (Listnode *)malloc(sizeof(Listnode));  
        tmpcell->next->next = NULL;
        tmpcell = tmpcell->next;
        tmpcell->val = c; //进位赋值
    }
    return L3;
}

//这一题写了我俩小时多，绝了
//最后结果跑的最快，就是内存消耗有点多，这个代码还可以优化一下，明天来
