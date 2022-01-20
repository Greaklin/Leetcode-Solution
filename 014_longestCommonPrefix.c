//solution01
//2022年01月15日
//这个好像类似14年还是15年的408真题，找最长公共前缀，但是真题没要求返回空串且只有俩字符串，真题比这个难度低得多
//为了减少遍历次数，直接拿第一个字符串去匹配后面的字符串即可
//明天继续复习指针数组的内容，把这题分析透。
char * longestCommonPrefix(char ** strs, int strsSize){
    unsigned int n = strlen(strs[1]);//把字符串数组的第一个子串内容当作最长前缀的初始项,之后遍历后续子串，拿第一个字符串去进行匹配
    char* zc = malloc(sizeof(char)*(n+1));
    int i =0;
    for(; i<n; i++)
    zc[i] = (strs[1])[i];//循环主体，逐个比较字符串内各元素
    zc[i] = '\0';
    return zc;
}

//2022年01月18日
//击败44.53%
char * longestCommonPrefix(char ** strs, int strsSize){
    unsigned int n = strlen(strs[0]);//把字符串数组的第一个子串内容当作最长前缀的初始项,之后遍历后续子串，拿第一个字符串去进行匹配
    char* zc = malloc(sizeof(char)*(n+1));
    for(int i = 0; i<n; i++)//公共前缀赋初始值
    zc[i] = (strs[0])[i];//循环主体，逐个比较字符串内各元素
    zc[n] = '\0';
    for(int i = 1; i<strsSize;i++){//从第2个字符串开始向后扫描，遍历全部字符串
        int j = 0;
        for(; zc[j]!='\0' && (strs[i])[j]!='\0'; j++)//对于每一个当前比较的字符串，如果当前的zc位不等于str当前比较的字符串的位，则将zc后续全部置空
            if(zc[j] != (strs[i])[j])  zc[j] = '\0';
        if(zc[j]!='\0' && (strs[i])[j]=='\0') zc[j] = '\0';//如果被比较str内的字符串更短则直接缩小zc的长度
    }
    return zc;
}

//优化改版，节省了一点空间，平均2ms，占用空间5.7MB击败70%
char * longestCommonPrefix(char ** strs, int strsSize){
//把字符串数组的第一个子串内容当作最长前缀的初始项,之后遍历后续子串，拿第一个字符串去进行匹配
    short n = strlen(strs[0])+1;
    char* zc = malloc(sizeof(char)*n);//利用sizeof测字符串包含了最后的'0'
    for(int i = 0; i<n ; i++)//公共前缀赋初始值
    zc[i] = (strs[0])[i];//循环主体，逐个比较字符串内各元素
    for(int i = 1; i<strsSize;i++){//从第2个字符串开始向后扫描，遍历全部字符串
        int j = 0;
        for(; zc[j]!='\0' && (strs[i])[j]!='\0'; j++)//对于每一个当前比较的字符串，如果当前的zc位不等于str当前比较的字符串的位，则将zc后续全部置空
            if(zc[j] != (strs[i])[j])  zc[j] = '\0';
        if(zc[j]!='\0' && (strs[i])[j]=='\0') zc[j] = '\0';//如果被比较str内的字符串更短则直接缩小zc的长度
    }
    return zc;
}
