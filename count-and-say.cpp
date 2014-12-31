class Solution {
/**
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

public:
    string countAndSay(int n) {
        string seq = "1";
        for(size_t i=1; i<n; i++){
            string next_seq;
            next_seq.clear();

            char c = seq[0];
            size_t cnt = 1;
            for(size_t j=1; j<seq.size(); j++){
                if(c == seq[j]) cnt++;
                else{
                    next_seq += cnt+'0';
                    next_seq += c;
                    c = seq[j];
                    cnt = 1;
                }
            }
            next_seq += cnt+'0';
            next_seq += c;

            seq.swap(next_seq);
        }
        
        return seq;
    }
};
