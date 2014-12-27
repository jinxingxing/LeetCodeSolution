/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev_row, curr_row;
        
        curr_row.push_back(1);
        for(size_t i=1; i<=rowIndex; i++){
            prev_row = curr_row;
            curr_row.clear();

            curr_row.push_back(1);
            for(size_t j=1; j<prev_row.size(); j++){
                curr_row.push_back(prev_row[j-1]+prev_row[j]);
            }
            curr_row.push_back(1);
        }
        
        return curr_row;
    }
};
