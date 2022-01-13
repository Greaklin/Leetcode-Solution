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
