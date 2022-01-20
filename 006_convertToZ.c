//Solution01
Incompleteation ED01
//1月07日，这题做了1小时了，之后得限制自己刷LeetCode的时间了。
//没想到低时间复杂度和空间复杂度的方案，这个中等题还是有难度的，之后看看标准答案题解怎么解，一天三小时这样自己琢磨太消耗时间了，很浪费。
//明天开始需要限制半小时内解题，如果没思路就看答案，过去，时间容不得这样消耗
//加油

//题目的意思应该是要返回一个新的数组回去，所以还是需要创建一个新的字符数组的
//可以用空间换时间，过需要用到内存，如果都能用局部变量解决那自然是最好
//输出按列排布，emm，估摸着后面会有非常长的，且题设提示不需要验证空串
//未知输入字符串长度是多少
//局部变量无法返回回去，必须得用malloc开辟新的辅助数组
//思路：
//在原空间的基础上进行修改，遍历一遍*s就不需要求出s的长度，malloc一下numRows的长度存储竖着的就可以了之后复制回对应字节位置
//暴力的话不停malloc最后numRows个串拼在一起
//用strlen可求出字符串长度
//length个字母，完整列数为length/numRows向下取整，即第1行的个数
//之后只需要按照这个取余对数组进行排布即可
char * convert(char * s, int numRows){
    short length = strlen(s);
    char *gg = (char *)malloc(sizeof(char)*20);
    for(int i = 0; i < length; i++)
        *gg++ ='a';
    return gg;
}

Incompleteation ED02
//2022年01月08日，不知道什么情况一直显示缓冲区溢出，十分的见鬼
//观察后能够得到代码中的规律，从左到右每2（numrows-1）个数就会开始新的一列
//即在新的字符串中，第2位对应下标为原字符串的第1+2（numrows-1）位
//就是第二行中间需要加一个减2的数，第三行减4，第四行减6。。。最后一行和第一行加一样的数
//居然和官解2的答案思路一致
//用i和j作为原式扫描
char * convert(char * s, int numRows){
    short length = strlen(s);//得到字符串长度
    char* new = malloc(sizeof(char)*(length+1));
    if(new == NULL && s == NULL)
        return NULL;
    int jg = 2*(numRows - 1), h = 0;//定义基本取值间隔与h的初始值
    for(int i = 0; i < numRows; i++)//行循环扫描取值
        for(int j = 0; j<length-jg-1; j += jg){//每次间隔一个jg
            if(j != 0 && (i != 0 || i != (numRows-1)))//如果不是首行且不在第一行或最后一行
            new[h++] = s[ j - 2*i ];
            new[h++] = s[j];
        }
    return new;
}

缓冲区溢出版本
//2022年01月11日
//在Xcode输入"a",1（即直接拷贝如下代码就可以直接看到堆缓冲区溢出）

char * convert(char * s, int numRows){
    unsigned int length = strlen(s);//得到字符串长度
    printf("%d\n",length);
    char* new = malloc(sizeof(char)*(length)+1);
    if(new == NULL)
        printf("gg");
    int jg = 2*(numRows - 1), js = 0;//定义基本取值间隔与h的初始值
    for(int i = 0; i < numRows; i++)//行循环扫描取值
        for(int j = i; j<length; j += jg){//每次间隔一个jg长度
            *(new++) = s[j];printf("d2:i=%d,j=%d,jd=%d,js=%d,new=%p,s=%c,new[js]=%s\n",i,j,jg,js++,new,s[ j ],new-js);
            if(i != 0&&i != numRows-1 &&(j+jg-2*i < length))//如果不是变换后首列且不在第一行或最后一行
            {*(new++) = s[ j + jg - 2*i ];printf("d1:i=%d,j=%d,jd=%d,js=%d,new=%p,s=%c,new[js]=%s\n",i,j,jg,js++,new,s[ j - 2*i ],new-js);}
            
        }
    return new-length;
}

int main(){
    char a[] = "a";
//    char *g =“linux”;
    short length = strlen(a);
    printf("%d\n",length);
    char* g = convert(a, 1);
    printf("%s\n",a);
    printf("%s\n",g);
}

完成版本
//2022年01月14日
//把官解改的和自己的一样，通过了，就差在19行的位置，很奇怪的原因，不知道什么毛病
// char * convert(char * s, int numRows){
//     if (numRows == 1) return s;
//     int n = strlen(s), x = 0;
//     char* ret = malloc(sizeof(char)*(n+1));//一样
//     int cycleLen = 2 * numRows - 2;//一样
//     for (int i = 0; i < numRows; i++)
//         for (int j = i; j < n; j += cycleLen) {
//             ret[x++] = s[j];
//             if (i != 0 && i != numRows - 1 && j + cycleLen - 2*i < n)
//                 ret[x++] = s[j + cycleLen - 2*i];
//         }
//     ret[x]='\0';
//     return ret;
// }
char * convert(char * s, int numRows){
    unsigned int length = strlen(s);//得到字符串长度
    if(numRows == 1) return s;//这一行和后一行互换后 “与”判断条件numRows >= length后会爆堆，不知道为什么
    char* new = malloc(sizeof(char)*(length+1));
    int jg = 2*(numRows - 1), js = 0;//定义基本取值间隔与h的初始值
    for(unsigned int i = 0; i < numRows; i++)//行循环扫描取值
        for(unsigned int j = i; j<length ; j += jg){//每次间隔一个jg长度
            new[js++] = s[j];
            if(i != 0&&i != numRows-1 && j+jg-2*i < length)//如果不是变换后首列且不在第一行或最后一行
            new[js++] = s[ j + jg - 2*i ];
        }
    new[js] = '\0';
    return new;
}

//时间击败100%，空间击败97.2%


//---------------------------------------------------------------------------------------------------------------------------------------------------------
//Solution02
//官方解法
//2022年01月13日
//修改标答思路二C++代码得到该C解法，明明是一个思路为什么我的是错的，循环逻辑上目前还不知道错在什么地方。
//该答案思路为按Z的行间隔规律对s进行扫描，找规律进行计算
char * convert(char * s, int numRows){
    if (numRows == 1) return s;//不加这一行会爆，目前还不清楚原因是什么
    int n = strlen(s), x = 0;
    char* ret = malloc(sizeof(char)*(n+1));//替代原C++代码中string类型
    int cycleLen = 2 * numRows - 2;
//循环主体基本一致，就是差在两个判断的地方，所以逻辑上原代码问题应该就在这两个逻辑上
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < n; j += cycleLen) {//这步差在判断上，最后都是+=cyclelen值不过我写的是jg，他这里写的是j+i<n而我是j<length，n=length
            ret[x++] = s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)//如果不是变换后首列且不在第一行或最后一行，我代码和该代码循环逻辑处差在了最后这个i上，这个点需要仔细思考！
                ret[x++] = s[j + cycleLen - i];
        }
    }
    ret[x]='\0';
    return ret;
}
