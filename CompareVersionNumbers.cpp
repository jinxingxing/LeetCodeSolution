/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t v1_pos = 0, v1_l = 0;
        size_t v2_pos = 0, v2_l = 0;

        while(v1_pos < version1.size() && v2_pos < version2.size()){
            v1_l = 1;
            while(v1_pos+v1_l < version1.size() &&
                    version1[v1_pos+v1_l] != '.'){
                v1_l++;
            }
            
            v2_l = 1;
            while(v2_pos+v2_l < version2.size() &&
                    version2[v2_pos+v2_l] != '.'){
                v2_l++;
            }
            
            int v1 = atoi(version1.substr(v1_pos, v1_l).c_str());
            int v2 = atoi(version2.substr(v2_pos, v2_l).c_str());
            if(v1 != v2) return v1 > v2 ? 1 : -1;
            
            v1_pos += v1_l;
            if(version1[v1_pos] == '.') v1_pos++;
            v2_pos += v2_l;
            if(version2[v2_pos] == '.') v2_pos++;
        }
        
        int v1 = 0;
        if(v1_pos < version1.size())
            v1 = atoi(version1.substr(v1_pos).c_str());
        int v2 = 0;
        if(v2_pos < version2.size())
            v2 = atoi(version2.substr(v2_pos).c_str());
            
        if(v1 == v2) return 0;
        return v1 > v2 ? 1 : -1;
    }
};
