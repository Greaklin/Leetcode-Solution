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
