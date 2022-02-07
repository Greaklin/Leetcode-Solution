//2022年02月07日
//半个月没写代码都忘的差不多了，啊啊啊啊啊啊啊啊啊，今天先再从官解做起吧，每天坚持，加油！
char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValid(char* s) {
    int n = strlen(s);//得到字符长度
    if (n % 2 == 1) {//如果串长度不是偶数这直接返回错误，简化后续运算
        return false;
    }
    int stk[n + 1], top = 0;//创建静态数组栈
    for (int i = 0; i < n; i++) {//遍历字符串for循环
        char ch = pairs(s[i]);//若扫描到左括号则ch=0，若扫描到右括号则ch转换成对应左括号
        if (ch) {//如果当前扫描到的比较字符是右括号，则和栈内的左括号进行比较，比较正确则出栈
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        } else {//如果当前扫描到的是左括号则入栈
            stk[top++] = s[i];
        }
    }
    return top == 0;//若栈空则返回正确
}
