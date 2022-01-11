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
