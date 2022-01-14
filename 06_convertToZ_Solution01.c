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
