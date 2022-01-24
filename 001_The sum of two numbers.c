//Solution01
//Here is a C code, which is a solution to the first test form LeeCode website.
//The sum of two numbers.


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *result=NULL;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                 result=(int*)malloc(sizeof(int)*2);
                 result[0]=i;
                 result[1]=j;
                 *returnSize=2;//需要设置returnsize才可以！
                 return result;
            }
        }
    }
    *returnSize=0;
    return result;
}


//Solution02
//Here is an official solution. I do not have the ability now to answer this question by using Hash map,
//so the task today is to make some marks in the following code. 
//This solution broads my horizon about How the Hash function can be defined.
//Not only can the Hash function be defined as the elements of nums table moding prime number, but also a subtraction between them.

struct hashTable {            //Statement of Hash Table struct
    int key;                  //key value used to mod the elements of nums table 
    int val;                  //存储元素数值
    UT_hash_handle hh;        //目前还不知道干啥的qwq
};

struct hashTable* hashtable;                          //The statement of a global variable named hashedtable whose type is the pointer of Hash Table struct
                                                      //声明哈希表的表头节点全局变量。
struct hashTable* find(int ikey) {                    //A function whose type is the pointer of Hash Table sturct whose content is about finding the complement element.
    struct hashTable* tmp;                            //声明tmp中间变量，用于存储后续查找哈希表的结果
    HASH_FIND_INT(hashtable, &ikey, tmp);             //The basic operation of Hash Map.如果在哈希表中找到了对应的元素就将其地址返回到tmp
    return tmp;                                       //返回tmp
}

void insert(int ikey, int ival) {                     //Insert the elements into Hash Map when searching the nums table. ikey为
    struct hashTable* it = find(ikey);                //调用find查找当前哈希表是否存在和ikey相同的元素
    if (it == NULL) {                                 //如果哈希表内没有对应元素值
        struct hashTable* tmp = malloc(sizeof(struct hashTable));//为哈希链表创建新的变量元素（时间不太够了用中文）
        tmp->key = ikey, tmp->val = ival;             //将主函数遍历到的元素进行中间变量赋值，结构体key对应
        HASH_ADD_INT(hashtable, key, tmp);            //The basic operation of Hash Map.哈希表的基础操作，往哈希表内添加元素。即将表头节点、关键字和已经进行好赋初值的tmp变量加入哈希表。
    } else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {   //The main function of this solution
    hashtable = NULL;                                                 //Initializing the global variable
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);                //该哈希函数的映射关系定义为目标减去对应值
        if (it != NULL) {                                             //找到了对应该哈希函数的元素，则进行返回
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;                                               //返回结果
        }
        insert(nums[i], i);                                           //没找到对应元素，则将该元素插入哈希表中
    }
    *returnSize = 0;
    return NULL;                                                      //没找到就什么都不返回
}


//01月24日继续摸鱼www
