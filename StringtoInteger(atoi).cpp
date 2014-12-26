class Solution {
public:
    int atoi(const char *str) {
        const char *p = str;
        long long rv = 0;
        int sign = 1;
        
        // 过滤开始的空白附
        while(*p == ' ') p++;
        
        // 取符号
        if(*p == '+') p++;
        else if(*p == '-'){
            sign = -1;
            p++;
        }
        
        while(*p){
            int n = (*p) - '0';
            if(n<0 || n>9)
                return rv*sign;  // 非数值
            rv = rv*10 + n;
            if(rv > INT_MAX)
                return (sign > 0 ? INT_MAX : INT_MIN); // 检查溢出
            p++;
        }
        
        return rv*sign;
    }
};
