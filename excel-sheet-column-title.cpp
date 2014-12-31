/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
   /**
    算法类似于进制转换，但又有很大不同
    如果按照26进制转换原则, A-Z 对应 0-25 (我们从0开始)，
    那么 26(示例中的27) 应该是 BA，而不是 AA
    按照示例，我们每一位(26进制的一位) -1 就对应上了（理论？？？）
    */
    string convertToTitle(int n) {
        string rv;
        while(n>0){
            n = n-1;
            rv += n%26 + 'A';
            n = n/26;
        };
        
        return string(rv.rbegin(), rv.rend());
    }
};
