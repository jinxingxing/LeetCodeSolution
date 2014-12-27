class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0) return false;
        
        int n=1;
        while(x/n>9){
            n = n*10;
        }
        
        while(x>0){
            if(x%10 != x/n) return false;
            x = (x%n) / 10;
            n = n/100;
        }
        return true;
    }
    
    // 字符串解法
    bool isPalindrome_Str(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        stringstream ss;
        ss << x;
        string s = ss.str();
        size_t i=0, j=s.size()-1;
        for(;i<j; i++,j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};Palindrome Number 
