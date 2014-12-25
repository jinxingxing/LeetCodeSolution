/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    typedef map<int,int> countMap;
    int majorityElement(vector<int> &num) {
        countMap count_map;
        for(size_t i=0; i<num.size(); i++){
            count_map[num[i]]++;
        }
        int n = num.size() / 2;
        int max = 0;
        int e;
        for(countMap::iterator iter = count_map.begin(); iter != count_map.end(); iter++){
            if(iter->second >= n && iter->second > max){
                max = iter->second;
                e = iter->first;
            }
        }
        
        return e;
    }
};
