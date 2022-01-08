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
