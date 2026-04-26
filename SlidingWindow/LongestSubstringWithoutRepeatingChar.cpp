// sliding window appraoch 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> myset;
        int l = 0, r = 0;
        int maxLen = 0;
        while(r < n){
            if(myset.find(s[r]) == myset.end()){
                myset.insert(s[r]);
                maxLen = max(maxLen, r - l + 1);
                r++;
            }else{
                myset.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};
