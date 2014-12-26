/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

更多示例：
convert("ABCD", 4):
A C
B D

convert("ABCDEFGHIJK", 4):
A     G
B   F H
C E   I K
D     J

* 按竖向的Z字型排列
*/

class Solution {
public:
    string convert(string s, int nRows) {
        //std::cout << s << "," << nRows << std::endl;
        if(nRows <= 1)
            return s;

        vector<string> vec(nRows);
        string rv;
        size_t row = 0;
        int delta = 1;
        for(size_t i=0; i<s.size(); i++){
            vec[row] += s[i];
            if(row == 0){
                delta = 1;
            }else if(row == nRows-1){
                delta = -1;
            }
            row += delta;
        }

        for(size_t i=0; i<vec.size(); i++){
            //std::cout << vec[i] << std::endl;
            rv += vec[i];
        }
        //std::cout << "-----------------" << std::endl;
        return rv;
    }
};
