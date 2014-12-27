/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

```
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```
*/



class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > rv;
        if(numRows <= 0) return rv;
        
        rv.push_back(vector<int>(1,1));
        for(size_t i=1; i<numRows; i++){
            vector<int> vec;
            vec.clear();
            vec.push_back(1);
            for(size_t j=1; j<rv.back().size(); j++){
                vec.push_back(rv.back()[j-1]+rv.back()[j]);
            }
            vec.push_back(1);
            rv.push_back(vec);
        }
        
        return rv;
    }
};
