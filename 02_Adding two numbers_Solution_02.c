//Official solution.

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *tail = NULL;//定义链输出链表头指针和尾指针
    int carry = 0;
    while (l1 || l2) {//当L1遇L2都没有遍历完则继续遍历
        int n1 = l1 ? l1->val : 0;//赋值n1，如果L1此时非空，则n1赋值为L1的数值，若L1此时遍历为空，则赋值为0
        int n2 = l2 ? l2->val : 0;//同理赋值n2，这种写法很好！
        int sum = n1 + n2 + carry;//将两个当前数值进行相加，并敬畏
        if (!head) {//对头节点单独进行赋值操作
            head = tail = malloc(sizeof(struct ListNode));//头尾节点统一赋值
            tail->val = sum % 10;//模10取余赋值尾指针当前所在节点，以方便尾指针后续行进
            tail->next = NULL;
        } else {//往后只修改尾节点，使用尾插法
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1) {//若L1非空，则L1指针指向下一个节点
            l1 = l1->next;
        }
        if (l2) {//L2同理
            l2 = l2->next;
        }
    }
    if (carry > 0) {//若循环结束还有剩余进位，则需要进一步进位
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return head;
}

//该段代码的时间复杂度仅遍历了一遍，为O（max（m，n））
//空间复杂度使用了：中间变量n1、n2、sum、carry、
